//
//  DHSkeleton.h
//  dhspine
//
//  Created by youbin on 13-9-30.
//
//

#ifndef __dhspine__DHSkeleton__
#define __dhspine__DHSkeleton__

#include "DHSkeletonData.h"
#include "DHBone.h"
#include "DHSlot.h"
#include "DHIkConstraint.h"
#include "DHPolygonBatch.h"
#include "DHRegionAttachment.h"
#include "DHSkinnedMeshAttachment.h"
#include "DHBoundingBoxAttachment.h"

NS_CC_BEGIN

class DHSkeleton : public Node {
    
    friend class DHAnimationData;

public:
    DHSkeleton(DHSkeletonData* const data);
    
    virtual ~DHSkeleton();
    
    static DHSkeleton* createWithKey(const char* const key);
    
    static DHSkeleton* createWithFile(const char* const jsonPath);
    
    static DHSkeleton* createWithData(DHSkeletonData* const data);
    
    virtual bool init();
    
    virtual void visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags);
    
    virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);
    
    virtual void drawSkeleton(const cocos2d::Mat4& transform, uint32_t flags);
    
    virtual bool drawSlot(DHSlot* slot);
    
    virtual void registerSkin(const char* skinName);
    
    virtual void unregisterSkin(const char* skinName);
    
    virtual void unregisterAllSkin();
    
    bool isSkinRegistered(const char* skinName);
    
    void setToSetupPose();
    
    void updateWorldTransform();
    
    DHAttachment* getAttachment(int slotIndex, const char* attachmentName);
    
    void setSkinEnabled(const char* skinName, bool enabled);
    
    bool containsPoint(const Point& point);//for each active boundingBox attachment
    
    bool containsPointBySlot(const char* slotName, const Point& point);//for each active boundingBox attachment by slot
    
    //get Line Segment Intersection
    std::pair<bool, Vec2> getIntersectionBySlot(const char* slotName, const Point& start, const Point& end);
    
    Size getAabbContentSize();
    
    Rect getAabbBoundingBox();
    
    Rect getAabbBoundingBoxBySlot(const char* slotName);
    
    bool aabbIntersectsSkeleton(DHSkeleton* other);
    
    bool regionContainsPoint(const Point& point);//for each active region attachment (image contentSize)
    
    bool aabbRegionContainsPoint(const Point& point);//for active region attachment (like sprite boundingBox)
    
    DrawNode* createDrawNodeBoundingBoxBySlot(const char* slotName, bool flipX = false);
    
    DHSkeletonData* const getData() const {
        return m_data;
    }
    
    float getAnimationDuration(const char* animName);
    
    float getEventTimeLine(const char* animName, const char* eventName);
    
    DHBone* getBoneByName(const char* boneName);
    
    DHBone* getBoneByIndex(int boneIndex);
    
    DHSlot* getSlotByName(const char* slotName);
    
    DHSlot* getSlotByIndex(int slotIndex);
    
    DHIkConstraint* getIkConstraints(int ikConstraintIndex);
    
    Point getBoneLocation(const char* boneName);
    
    Point getBonePosition(const char* boneName);
    
    Point getBonePositionRelativeToLayer(const char* boneName);
    
    Point getBonePositionRelativeToWorld(const char* boneName);
    
    virtual void setColor(const Color3B& color);
    
    virtual void setOpacity(GLubyte opacity);
    
    void setExtendColor(const Color4F& color);
    
    void setExtendOpacity(GLfloat opacity);
    
    GLfloat getExtendOpacity() const;
    
    const Color4F& getExtendColor() const;
    
    const Color4F& getReallyColor() const;
    
    GLfloat getReallyOpacity() const;
    
    void setFlipX(bool flipX);
    
    void setFlipY(bool flipY);
    
    bool isFlipX() const {
        return m_flipX;
    }
    
    bool isFlipY() const {
        return m_flipY;
    }
    
    void setAllSlotColorEnabled(bool colorEnabled);
    
    void addChildFollowBone(const char* boneName, Node* child);
    
    void addChildFollowSlot(const char* slotName, Node* child, bool enabledFollowColor = true);
    
    void removeChildFollowBone(const char* boneName);
    
    void removeChildFollowSlot(const char* slotName);
    
    Node* getChildFollowBone(const char* boneName);
    
    Node* getChildFollowSlot(const char* slotName);
    
    virtual void removeChild(Node* child);
    
    virtual void removeChild(Node* child, bool cleanup);
    
    void removeSlotFollowAttachment(Node* followAttachment);
    
    bool isColorMixEnabled() {
        return m_colorMixEnabled;
    }
    
    void setColorMixEnabled(bool enabled) {
        m_colorMixEnabled = enabled;
    }
    
    //color rotating by hue
    float getHue(const std::string& slotName);
    
    void setHue(const std::string& slotName, float hue);
    
    float getSaturation(const std::string& slotName);
    
    void setSaturation(const std::string& slotName, float saturation);
    
    float getBrightness(const std::string& slotName);
    
    void setBrightness(const std::string& slotName, float brightness);
    
    bool isColorRotationInit() const {
        return m_colorRotationInit;
    }
    
    void setUseCulling(bool useCulling) {
        m_useCulling = useCulling;
    }
    
    bool isUseCulling() const {
        return m_useCulling;
    }
    
protected:
    DHSkeleton();
    
    virtual void updateColor();
    
    void updateCache();
    
    void updateBone();
    
    void updateSlot();
    
    void resetDrawOrder();
    
    void setDrawOrder(const int* drawOrder);
    
    //color rotating by hue
    void colorRotationLazyInit();
    
protected:
    
    DHSkeletonData* const m_data;
    
    DHBone** m_bones;
    DHSlot** m_slots;
    DHSlot** m_drawOrder;
    
    DHDictionary* m_skinMap;
    
    std::set<Node*> m_slotFollowAttachmentSet;
    
    static DHPolygonBatch* m_batch;
    
protected:
    bool m_flipX;
    bool m_flipY;
    
    Color4F m_color;
    Color4F m_realColor;
    
    bool m_colorMixEnabled;
    
    DHIkConstraint** m_ikConstraints;
    
    unsigned int m_boneCacheCount;
    int* m_boneCacheCounts;
    DHBone*** m_boneCache;
    
    int m_drawSlotIndex;
    std::vector<CustomCommand*> m_drawCommandVec;
    
    std::map<std::string, float> m_hueMap;
    std::map<std::string, float> m_saturationMap;
    std::map<std::string, float> m_brightnessMap;
    bool m_colorRotationInit;
    
    bool m_drawOrderDirty;
    bool m_useCulling;
};

NS_CC_END


#endif /* defined(__dhspine__DHSkeleton__) */
