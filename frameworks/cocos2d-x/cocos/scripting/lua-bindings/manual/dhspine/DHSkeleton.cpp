//
//  DHSkeleton.cpp
//  dhspine
//
//  Created by youbin on 13-9-30.
//
//

#include "DHSkeleton.h"
#include "DHSkeletonAnimation.h"
#include "DHSlot.h"
#include "DHSkeletonDataCache.h"

NS_CC_BEGIN

DHPolygonBatch* DHSkeleton::m_batch = nullptr;

DHSkeleton::DHSkeleton()
:m_data(nullptr)
,m_color(1, 1, 1, 1)
,m_realColor(1, 1, 1, 1)
,m_flipX(false)
,m_flipY(false)
,m_skinMap(nullptr)
,m_drawOrder(nullptr)
,m_colorMixEnabled(false)
,m_ikConstraints(nullptr)
,m_boneCache(nullptr)
,m_boneCacheCounts(nullptr)
,m_colorRotationInit(false)
,m_drawOrderDirty(false)
,m_useCulling(true) {
    
}

DHSkeleton::DHSkeleton(DHSkeletonData* const data)
:m_data(data)
,m_color(1, 1, 1, 1)
,m_realColor(1, 1, 1, 1)
,m_flipX(false)
,m_flipY(false)
,m_drawOrder(nullptr)
,m_colorMixEnabled(false)
,m_ikConstraints(nullptr)
,m_boneCache(nullptr)
,m_boneCacheCounts(nullptr)
,m_colorRotationInit(false)
,m_drawOrderDirty(false)
,m_useCulling(true) {
    m_data->retain();
    m_skinMap = new DHDictionary();
    
    if (m_batch == nullptr) {
        m_batch = new DHPolygonBatch();
        m_batch->initGLView();
    }
}

DHSkeleton::~DHSkeleton() {
    DH_ARRAY_DELETE(m_bones, m_data->getBoneCount())
    DH_ARRAY_DELETE(m_slots, m_data->getSlotCount())
    DH_ARRAY_DELETE(m_ikConstraints, m_data->getIkConstraintCount())
    
    CC_SAFE_DELETE_ARRAY(m_drawOrder);
    
    CC_SAFE_DELETE(m_skinMap);
    
    DH_ARRAY_DELETE(m_boneCache, m_boneCacheCount)
    
    CC_SAFE_DELETE_ARRAY(m_boneCacheCounts);
    
    CC_SAFE_RELEASE(m_data);
    
    for (const auto& iter : m_drawCommandVec) {
        delete iter;
    }
    m_drawCommandVec.clear();
}

DHSkeleton* DHSkeleton::createWithKey(const char* const key) {
    DHSkeletonData* data = SDC->getSkeletonData(key);
    if (data) {
        return createWithData(data);
    }
    CCLOGWARN("the SkeletonData key: %s is not find", key);
    return nullptr;
}

DHSkeleton* DHSkeleton::createWithFile(const char* const jsonPath) {
    DHSkeletonData* data = DHSpineLoader::loadSkeletonData(jsonPath);
    if (data) {
        return createWithData(data);
    }
    CCLOGWARN("the jsonPath: %s is not find", jsonPath);
    return nullptr;
}

DHSkeleton* DHSkeleton::createWithData(DHSkeletonData* const data) {
    DHSkeleton* skeleton = new DHSkeleton(data);
    if (skeleton && skeleton->init()) {
        return (DHSkeleton*)skeleton->autorelease();
    }
    CC_SAFE_RELEASE(skeleton);
    return nullptr;
}

bool DHSkeleton::init() {
    if (!m_data || !Node::init()) {
        return false;
    }
    
    m_bones = m_data->newBones();
    
    m_slots = m_data->newSlots(this);
    
    m_drawOrder = new DHSlot*[m_data->getSlotCount()];
    memcpy(m_drawOrder, m_slots, sizeof(DHSlot*) * m_data->getSlotCount());
    
    m_ikConstraints = m_data->newIkConstraints(this);
    
    updateCache();
    
    updateWorldTransform();
    
    setGLProgram(GLProgramCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_TEXTURE_COLOR_NO_MVP));
    
    return true;
}

void DHSkeleton::updateCache() {
    DH_ARRAY_DELETE(m_boneCache, m_boneCacheCount)
    
    CC_SAFE_DELETE_ARRAY(m_boneCacheCounts);
    
    m_boneCacheCount = m_data->getIkConstraintCount() + 1;
    m_boneCache = new DHBone**[m_boneCacheCount];
    m_boneCacheCounts = new int[m_boneCacheCount];
    
    memset(m_boneCacheCounts, 0, m_boneCacheCount * sizeof(int));
    
    /* Compute array sizes. */
    for (int i = 0; i < m_data->getBoneCount(); ++i) {
        DHBone* current = m_bones[i];
        
        do {
            for (int j = 0; j < m_data->getIkConstraintCount(); ++j) {
                DHIkConstraint* ikConstraint = m_ikConstraints[j];
                DHBone* parent = ikConstraint->m_bones[0];
                DHBone* child = ikConstraint->m_bones[ikConstraint->m_bonesCount - 1];
                while (1) {
                    if (current == child) {
                        m_boneCacheCounts[j]++;
                        m_boneCacheCounts[j + 1]++;
                        goto outer1;
                    }
                    if (child == parent) {
                        break;
                    }
                    child = child->m_parent;
                }
            }
            current = current->m_parent;
        } while (current);
        m_boneCacheCounts[0]++;
        outer1: {}
    }
    
    for (int i = 0; i < m_boneCacheCount; ++i) {
        m_boneCache[i] = new DHBone*[m_boneCacheCounts[i]];
    }
    memset(m_boneCacheCounts, 0, m_boneCacheCount * sizeof(int));
    
    /* Populate arrays. */
    for (int i = 0; i < m_data->getBoneCount(); ++i) {
        DHBone* bone = m_bones[i];
        DHBone* current = bone;
        do {
            for (int j = 0; j < m_data->getIkConstraintCount(); ++j) {
                DHIkConstraint* ikConstraint = m_ikConstraints[j];
                DHBone* parent = ikConstraint->m_bones[0];
                DHBone* child = ikConstraint->m_bones[ikConstraint->m_bonesCount - 1];
                while (1) {
                    if (current == child) {
                        m_boneCache[j][m_boneCacheCounts[j]++] = bone;
                        m_boneCache[j + 1][m_boneCacheCounts[j + 1]++] = bone;
                        goto outer2;
                    }
                    if (child == parent) {
                       break;
                    }
                    child = child->m_parent;
                }
            }
            current = current->m_parent;
        } while (current);
        m_boneCache[0][m_boneCacheCounts[0]++] = bone;
        outer2: {}
    }
}

void DHSkeleton::setToSetupPose() {
    DH_ARRAY_FOREACH(m_data->getBoneCount()) {
        m_bones[i]->setToSetupPose();
    }
    
    DH_ARRAY_FOREACH(m_data->getSlotCount()) {
        m_slots[i]->setToSetupPose();
    }
    
    DH_ARRAY_FOREACH(m_data->getIkConstraintCount()) {
        m_ikConstraints[i]->setToSetupPose();
    }
    
    resetDrawOrder();
}

void DHSkeleton::updateWorldTransform() {
    updateBone();
    updateSlot();
}

void DHSkeleton::updateBone() {
    DH_ARRAY_FOREACH(m_data->getBoneCount()) {
        m_bones[i]->m_rotationIK = m_bones[i]->m_rotation;
    }
    
    int i = 0;
    int last = m_boneCacheCount - 1;
    while (1) {
        const int size = m_boneCacheCounts[i];
        for (int j = 0; j < size; ++j) {
            m_boneCache[i][j]->updateWorldTransform();
        }
        if (i == last) {
            break;
        }
        m_ikConstraints[i++]->apply();
    }
}

void DHSkeleton::updateSlot() {
    DH_ARRAY_FOREACH(m_data->getSlotCount()) {
        m_slots[i]->updateAttachment();
    }
}

void DHSkeleton::resetDrawOrder() {
    if (m_drawOrderDirty) {
        memcpy(m_drawOrder, m_slots, sizeof(DHSlot*) * m_data->getSlotCount());
        m_drawOrderDirty = false;
    }
}

void DHSkeleton::setDrawOrder(const int *drawOrder) {
    if (!drawOrder) {
        resetDrawOrder();
    }
    else {
        m_drawOrderDirty = true;
        DH_ARRAY_FOREACH(m_data->getSlotCount()) {
            m_drawOrder[i] = m_slots[drawOrder[i]];
        }
    }
}

DHAttachment* DHSkeleton::getAttachment(int slotIndex, const char *attachmentName) {
    if (!attachmentName) {
        return nullptr;
    }
    DHDictElement* element;
    DH_DICT_FOREACH(m_skinMap, element) {
        DHSkin* skin = (DHSkin*)element->value;
        DHAttachment* attachment = skin->getAttachment(slotIndex, attachmentName);
        if (attachment) {
            return attachment;
        }
    }
    return m_data->getDefaultAttachment(slotIndex, attachmentName);
}

void DHSkeleton::visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags) {
    // quick return if not visible. children won't be drawn.
    if (!_visible)
    {
        return;
    }
    
    uint32_t flags = processParentFlags(parentTransform, parentFlags);
    
    // IMPORTANT:
    // To ease the migration to v3.0, we still support the Mat4 stack,
    // but it is deprecated and your code should not rely on it
    Director* director = Director::getInstance();
    director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, _modelViewTransform);
    
    DH_ARRAY_FOREACH(m_data->getBoneCount()) {
        m_bones[i]->updateFollowAttachment(isFlipX(), isFlipY());
    }
    
    bool visibleByCamera = isVisitableByVisitingCamera();
    
    int i = 0;
    
    if(!_children.empty())
    {
        sortAllChildren();
        // draw children zOrder < 0
        for( ; i < _children.size(); i++ )
        {
            auto node = _children.at(i);
            
            if ( node && node->getLocalZOrder() < 0 ) {
                if (m_slotFollowAttachmentSet.find(node) == m_slotFollowAttachmentSet.end()) {
                    node->visit(renderer, _modelViewTransform, flags);
                }
            }
            else
                break;
        }
        // self draw
        if (visibleByCamera)
            this->draw(renderer, _modelViewTransform, flags);
        
        for(auto it=_children.cbegin()+i; it != _children.cend(); ++it) {
            auto node = *it;
            if (node && m_slotFollowAttachmentSet.find(node) == m_slotFollowAttachmentSet.end()) {
                node->visit(renderer, _modelViewTransform, flags);
            }
            
        }
    }
    else if (visibleByCamera)
    {
        this->draw(renderer, _modelViewTransform, flags);
    }
    
    director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
}

void DHSkeleton::draw(Renderer *renderer, const Mat4& transform, uint32_t flags) {
    int drawCommandIndex = 0;
    auto addDrawCommad = [&]() {
        if (drawCommandIndex >= m_drawCommandVec.size()) {
            m_drawCommandVec.push_back(new CustomCommand());
        }
        
        CustomCommand* drawCommand = m_drawCommandVec[drawCommandIndex++];
        drawCommand->init(_globalZOrder);
        drawCommand->func = CC_CALLBACK_0(DHSkeleton::drawSkeleton, this, transform, flags);
        renderer->addCommand(drawCommand);
    };
    
    DH_ARRAY_FOREACH(m_data->getSlotCount()) {
        DHSlot* slot = m_drawOrder[i];
        
        if (slot->updateFollowAttachment()) {
            addDrawCommad();
            slot->drawFollowAttachment(renderer, transform, flags);
        }
        
        DHAttachment* attachment = slot->getAttachment();
        if (attachment) {
            switch (attachment->getType()) {
                case DHAttachmentType::at_region:
                case DHAttachmentType::at_mesh:
                case DHAttachmentType::at_skinned_mesh: {
                    DHRegionAttachment* regionAttachment = (DHRegionAttachment*)attachment;
                    if (m_batch->addBuffer(regionAttachment)) {
                        addDrawCommad();
                    }
                    break;
                }
                default:
                    break;
            }
        }
    }
    
    if (m_batch->getVerticesCount() > 0) {
        addDrawCommad();
        m_batch->resetBuffer();
    }
    
    m_drawSlotIndex = 0;
}

bool DHSkeleton::drawSlot(DHSlot* slot) {
    if (slot->isEnabledFollowAttachment()) {
        m_batch->flush();
        return true;
    }
    
    DHAttachment* attachment = slot->getAttachment();
    if (attachment) {
        switch (attachment->getType()) {
            case DHAttachmentType::at_region:
            case DHAttachmentType::at_mesh:
            case DHAttachmentType::at_skinned_mesh: {
                DHRegionAttachment* regionAttachment = (DHRegionAttachment*)attachment;
                if (m_batch->addDrawCmd(regionAttachment, slot, m_useCulling)) {
                    return true;
                }
                break;
            }
            default:
                break;
        }
    }
    return false;
}

void DHSkeleton::drawSkeleton(const cocos2d::Mat4 &transform, uint32_t flags) {
    getGLProgramState()->apply(transform);
    
    m_batch->apply(this, transform);
    
    while (m_drawSlotIndex < m_data->getSlotCount()) {
        if (drawSlot(m_drawOrder[m_drawSlotIndex++])) {
            return;
        }
    }
    
    m_batch->flush();
}

void DHSkeleton::registerSkin(const char *skinName) {
    DHSkin* skin = m_data->findSkin(skinName);
    if (!skin) {
        CCLOGERROR("the skin : %s is not find!",skinName);
        return;
    }
    m_skinMap->insert(skinName, skin);
    
    updateSlot();
}

void DHSkeleton::unregisterSkin(const char *skinName) {
    m_skinMap->remove(skinName);
    updateSlot();
}

void DHSkeleton::unregisterAllSkin() {
    m_skinMap->removeAll();
    updateSlot();
}

bool DHSkeleton::isSkinRegistered(const char *skinName) {
    return m_skinMap->find(skinName) != nullptr;
}

void DHSkeleton::setSkinEnabled(const char *skinName, bool enabled) {
    enabled ? registerSkin(skinName) : unregisterSkin(skinName);
}

bool DHSkeleton::containsPoint(const cocos2d::Point &point) {
    Point pos = convertToNodeSpace(point);
    DH_ARRAY_FOREACH(m_data->getSlotCount()) {
        DHBoundingBoxAttachment* attachment = m_slots[i]->getBoundingBoxAttachment();
        if (attachment && attachment->containsPoint(m_slots[i], pos.x, pos.y)) {
            return true;
        }
    }
    return false;
}

bool DHSkeleton::containsPointBySlot(const char *slotName, const cocos2d::Point &point) {
    DHSlot* slot = getSlotByName(slotName);
    
    if (slot) {
        Point pos = convertToNodeSpace(point);
        DHBoundingBoxAttachment* attachment = slot->getBoundingBoxAttachment();
        return attachment && attachment->containsPoint(slot, pos.x, pos.y);
    }
    
    return false;
}

std::pair<bool, Vec2> DHSkeleton::getIntersectionBySlot(const char* slotName, const Point& start, const Point& end) {
    bool ok = false;
    Vec2 res = Vec2::ZERO;
    DHSlot* slot = getSlotByName(slotName);
    
    if (slot) {
        Point startLoc = convertToNodeSpace(start);
        Point endLoc = convertToNodeSpace(end);
        DHBoundingBoxAttachment* attachment = slot->getBoundingBoxAttachment();
        if (attachment) {
            ok = attachment->getIntersection(slot, start, end, res);
        }
    }
    
    return std::pair<bool, Vec2>(ok, res);
}

Size DHSkeleton::getAabbContentSize() {
    Point aa = Point(INT_MAX, INT_MAX);
    Point bb = Point(INT_MIN, INT_MIN);
    
    DH_ARRAY_FOREACH(m_data->getSlotCount()) {
        DHBoundingBoxAttachment* attachment = m_slots[i]->getBoundingBoxAttachment();
        if (attachment) {
            attachment->updateAabb(m_slots[i], aa.x, aa.y, bb.x, bb.y);
        }
    }
    
    return Size(bb.x - aa.x, bb.y - aa.y);
}

Rect DHSkeleton::getAabbBoundingBox() {
    Point aa = Point(INT_MAX, INT_MAX);
    Point bb = Point(INT_MIN, INT_MIN);
    
    DH_ARRAY_FOREACH(m_data->getSlotCount()) {
        DHBoundingBoxAttachment* attachment = m_slots[i]->getBoundingBoxAttachment();
        if (attachment) {
            attachment->updateAabb(m_slots[i], aa.x, aa.y, bb.x, bb.y);
        }
    }
    aa = convertToWorldSpace(aa);
    bb = convertToWorldSpace(bb);

    return Rect(aa.x, aa.y, bb.x - aa.x, bb.y - aa.y);
}

Rect DHSkeleton::getAabbBoundingBoxBySlot(const char* slotName) {
    DHSlot* slot = getSlotByName(slotName);
    if (slot) {
        DHBoundingBoxAttachment* attachment = slot->getBoundingBoxAttachment();
        if (attachment) {
            Point aa = Point(INT_MAX, INT_MAX);
            Point bb = Point(INT_MIN, INT_MIN);
            
            attachment->updateAabb(slot, aa.x, aa.y, bb.x, bb.y);
            
            aa = convertToWorldSpace(aa);
            bb = convertToWorldSpace(bb);
            
            return Rect(aa.x, aa.y, bb.x - aa.x, bb.y - aa.y);
        }
    }
    return Rect::ZERO;
}

bool DHSkeleton::aabbIntersectsSkeleton(cocos2d::DHSkeleton *other) {
    Rect slefRec = getAabbBoundingBox();
    return slefRec.intersectsRect(other->getAabbBoundingBox());
}

bool DHSkeleton::regionContainsPoint(const cocos2d::Point &point) {
    Point pos = convertToNodeSpace(point);
    DH_ARRAY_FOREACH(m_data->getSlotCount()) {
        DHRegionAttachment* attachment = m_slots[i]->getRegionAttachment();
        if (attachment && attachment->containsPoint(m_slots[i], pos.x, pos.y)) {
            return true;
        }
    }
    return false;
}

bool DHSkeleton::aabbRegionContainsPoint(const cocos2d::Point &point) {
    Point pos = convertToNodeSpace(point);
    float minX = INT_MAX;
    float minY = INT_MAX;
    float maxX = INT_MIN;
    float maxY = INT_MIN;
    DH_ARRAY_FOREACH(m_data->getSlotCount()) {
        DHRegionAttachment* attachment = m_slots[i]->getRegionAttachment();
        if (attachment) {
            attachment->updateAabb(m_slots[i], minX, minY, maxX, maxY);
        }
    }
    return pos.x >= minX && pos.x <= maxX && pos.y >= minY && pos.y <= maxY;
}

DrawNode* DHSkeleton::createDrawNodeBoundingBoxBySlot(const char *slotName, bool flipX) {
    DHSlot* slot = getSlotByName(slotName);
    
    if (slot) {
        DHBoundingBoxAttachment* attachment = slot->getBoundingBoxAttachment();
        attachment->setCurrentSlot(slot);
        
        int verticesCount = attachment->getVerticesCount();
        int pointCount = verticesCount >> 1;
        Point* pointAry = new Point[pointCount]();

        for (int i = 0; i < verticesCount; i += 2) {
            attachment->computeWorldVertices(pointAry[i >> 1].x, pointAry[i >> 1].y, i);
            if (flipX) {
                pointAry[i >> 1].x *= -1;
            }
        }
        
        DrawNode* drawNode = DrawNode::create();
        
        Color4F black = Color4F(1, 1, 1, 1);
        drawNode->drawPolygon(pointAry, pointCount, black, 1, black);
        
        delete [] pointAry;
        
        return drawNode;
    }
    
    return nullptr;
}

DHBone* DHSkeleton::getBoneByName(const char *boneName) {
    int index = m_data->findBoneIndex(boneName);
    if (index >= 0) {
        return getBoneByIndex(index);
    }
    CCLOGERROR("the bone(%s) is not find!", boneName);
    return nullptr;
}

DHBone* DHSkeleton::getBoneByIndex(int boneIndex) {
    return m_bones[boneIndex];
}

DHSlot* DHSkeleton::getSlotByName(const char *slotName) {
    int index = m_data->findSlotIndex(slotName);
    if (index >= 0) {
        return getSlotByIndex(index);
    }
    CCLOGERROR("the slot(%s) is not find!", slotName);
    return nullptr;
}

DHSlot* DHSkeleton::getSlotByIndex(int slotIndex) {
    return m_slots[slotIndex];
}

DHIkConstraint* DHSkeleton::getIkConstraints(int ikConstraintIndex) {
    return m_ikConstraints[ikConstraintIndex];
}

Point DHSkeleton::getBoneLocation(const char *boneName) {
    DHBone* bone = getBoneByName(boneName);
    if (bone) {
        Point pos = Vec2(bone->m_worldX, bone->m_worldY);
        if (isFlipX()) {
            pos.x = -pos.x;
        }
        if (isFlipY()) {
            pos.y = -pos.y;
        }
        return pos;
    }
    return Vec2::ZERO;
}

Point DHSkeleton::getBonePosition(const char *boneName) {
    return PointApplyAffineTransform(getBoneLocation(boneName), getNodeToParentAffineTransform());
}

Point DHSkeleton::getBonePositionRelativeToLayer(const char *boneName) {
    AffineTransform t = this->getNodeToParentAffineTransform();
    
    Node* father;
    for (Node *p = _parent; p != nullptr; p = father) {
        father = p->getParent();
        if (!father || !father->getParent()) {
            break;
        }
        t = AffineTransformConcat(t, p->getNodeToParentAffineTransform());
    }

    return PointApplyAffineTransform(getBoneLocation(boneName), t);
}

Point DHSkeleton::getBonePositionRelativeToWorld(const char *boneName) {
    AffineTransform t = this->getNodeToParentAffineTransform();
    
    Node* father;
    for (Node *p = _parent; p != nullptr; p = father) {
        father = p->getParent();
        if (!father) {
            break;
        }
        t = AffineTransformConcat(t, p->getNodeToParentAffineTransform());
    }
    
    return PointApplyAffineTransform(getBoneLocation(boneName), t);
}

void DHSkeleton::setColor(const Color3B& color) {
    if (color != _realColor) {
        Node::setColor(color);
        m_realColor.r = m_color.r * _displayedColor.r / 255.f;
        m_realColor.g = m_color.g * _displayedColor.g / 255.f;
        m_realColor.b = m_color.b * _displayedColor.b / 255.f;
    }
}

void DHSkeleton::setOpacity(GLubyte opacity) {
    if (opacity != _realOpacity) {
        Node::setOpacity(opacity);
        m_realColor.a = m_color.a * _displayedOpacity / 255.f;
    }
}

void DHSkeleton::updateColor() {
    m_realColor.r = m_color.r * _displayedColor.r / 255.f;
    m_realColor.g = m_color.g * _displayedColor.g / 255.f;
    m_realColor.b = m_color.b * _displayedColor.b / 255.f;
    m_realColor.a = m_color.a * _displayedOpacity / 255.f;
}

void DHSkeleton::setExtendColor(const Color4F& color) {
    if (m_color != color) {
        m_color = color;
        m_realColor.r = m_color.r * _displayedColor.r / 255.f;
        m_realColor.g = m_color.g * _displayedColor.g / 255.f;
        m_realColor.b = m_color.b * _displayedColor.b / 255.f;
        m_realColor.a = m_color.a * _displayedOpacity / 255.f;
    }
}

void DHSkeleton::setExtendOpacity(GLfloat opacity) {
    if (opacity != m_color.a) {
        m_color.a = opacity;
        m_realColor.a = m_color.a * _displayedOpacity / 255.f;
    }
}

const Color4F& DHSkeleton::getExtendColor() const {
    return m_color;
}

GLfloat DHSkeleton::getExtendOpacity() const {
    return m_color.a;
}

const Color4F& DHSkeleton::getReallyColor() const {
    return m_realColor;
}

GLfloat DHSkeleton::getReallyOpacity() const {
    return m_realColor.a;
}

void DHSkeleton::setFlipX(bool flipX) {
    m_flipX = flipX;
}

void DHSkeleton::setFlipY(bool flipY) {
    m_flipY = flipY;
}

void DHSkeleton::setAllSlotColorEnabled(bool colorEnabled) {
    DH_ARRAY_FOREACH(m_data->getSlotCount()) {
        m_slots[i]->setColorEnabled(colorEnabled);
    }
}

void DHSkeleton::addChildFollowBone(const char *boneName, cocos2d::Node *child) {
    DHBone* bone = getBoneByName(boneName);
    if (bone) {
        Node* virNode = Node::create();
        this->addChild(virNode, child->getLocalZOrder(), child->getTag());
        virNode->addChild(child);
        
        bone->addFollowAttachment(virNode);
    }
}

void DHSkeleton::addChildFollowSlot(const char *slotName, cocos2d::Node *child, bool enabledFollowColor) {
    DHSlot* slot = getSlotByName(slotName);
    if (slot) {
        Node* virNode = Node::create();
        this->addChild(virNode, child->getLocalZOrder(), child->getTag());
        virNode->addChild(child);
        
        slot->addFollowAttachment(virNode, enabledFollowColor);
        
        m_slotFollowAttachmentSet.insert(virNode);
    }
}

void DHSkeleton::removeChildFollowBone(const char *boneName) {
    DHBone* bone = getBoneByName(boneName);
    if (bone) {
        bone->removeFollowAttachment();
    }
}

void DHSkeleton::removeChildFollowSlot(const char *slotName) {
    DHSlot* slot = getSlotByName(slotName);
    if (slot) {
        slot->removeFollowAttachment();
    }
}

Node* DHSkeleton::getChildFollowBone(const char *boneName) {
    DHBone* bone = getBoneByName(boneName);
    if (bone) {
        return bone->getFollowAttachmentChild();
    }
    return nullptr;
}

Node* DHSkeleton::getChildFollowSlot(const char *slotName) {
    DHSlot* slot = getSlotByName(slotName);
    if (slot) {
        return slot->getFollowAttachmentChild();
    }
    return nullptr;
}

void DHSkeleton::removeChild(cocos2d::Node *child) {
    this->removeChild(child, true);
}

void DHSkeleton::removeChild(cocos2d::Node *child, bool cleanup) {
    if (_children.contains(child)) {
        Node::removeChild(child, cleanup);
    }
    else {
        Node::removeChild(child->getParent(), cleanup);
    }
}

void DHSkeleton::removeSlotFollowAttachment(Node* followAttachment) {
    m_slotFollowAttachmentSet.erase(followAttachment);
}

void DHSkeleton::colorRotationLazyInit() {
    if (!m_colorRotationInit) {
        m_colorRotationInit = true;
        
        auto glprogram = DHSkeletonDataCache::getInstance()->getGLProgram("hue_program");
        auto glprogramstate = cocos2d::GLProgramState::create(glprogram);
        setGLProgramState(glprogramstate);
        
        glprogramstate->setUniformCallback("u_hue", CC_CALLBACK_2(DHPolygonBatch::hueUniformCallback, m_batch));
    }
}

float DHSkeleton::getHue(const std::string& slotName) {
    auto iter = m_hueMap.find(slotName);
    if (iter != m_hueMap.end()) {
        return iter->second;
    }
    return 0.f;
}

void DHSkeleton::setHue(const std::string& slotName, float hue) {
    colorRotationLazyInit();
    
    m_hueMap[slotName] = hue * PI / 180.f;
}

float DHSkeleton::getSaturation(const std::string& slotName) {
    auto iter = m_saturationMap.find(slotName);
    if (iter != m_saturationMap.end()) {
        return iter->second;
    }
    return 1.f;
}

void DHSkeleton::setSaturation(const std::string& slotName, float saturation) {
    colorRotationLazyInit();
    
    m_saturationMap[slotName] = saturation;
}

float DHSkeleton::getBrightness(const std::string& slotName) {
    auto iter = m_brightnessMap.find(slotName);
    if (iter != m_brightnessMap.end()) {
        return iter->second;
    }
    return 1.f;
}

void DHSkeleton::setBrightness(const std::string& slotName, float brightness) {
    colorRotationLazyInit();
    
    m_brightnessMap[slotName] = brightness;
}

float DHSkeleton::getAnimationDuration(const char* animName) {
    auto animData = getData()->findAnimaion(animName);
    if (animData) {
        return animData->getDuration();
    }
    return 0.f;
}

float DHSkeleton::getEventTimeLine(const char* animName, const char* eventName) {
    auto animData = getData()->findAnimaion(animName);
    if (animData) {
        return animData->getLastEventTimeByName(eventName);
    }
    return 0.f;
}

NS_CC_END