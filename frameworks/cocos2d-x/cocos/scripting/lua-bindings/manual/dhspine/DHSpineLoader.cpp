//
//  DHSpineLoader.cpp
//  dhspine
//
//  Created by youbin on 13-10-3.
//
//

#include "DHSpineLoader.h"
#include "DHBoneTransform.h"
#include "DHSlotTransform.h"
#include "DHRegionAttachment.h"
#include "DHMeshAttachment.h"
#include "DHSkinnedMeshAttachment.h"
#include "DHBoundingBoxAttachment.h"
#include "xxtea.h"

NS_CC_BEGIN

char* DHSpineLoader::relativeFilePath = nullptr;
float DHSpineLoader::resolutionScale = 1.f;
bool  DHSpineLoader::m_xxteaEnabled = false;
char* DHSpineLoader::m_xxteaKey = nullptr;
int   DHSpineLoader::m_xxteaKeyLen = 0;
char* DHSpineLoader::m_xxteaSign = nullptr;
int   DHSpineLoader::m_xxteaSignLen = 0;

GLfloat DHSpineLoader::toColor(const char *value, int index) {
    char digits[3];
	value += index * 2;
	digits[0] = *value;
	digits[1] = *(value + 1);
	digits[2] = '\0';
	return strtoul(digits, nullptr, 16) / 255.f;
}

DHSkeletonData* DHSpineLoader::loadSkeletonFromData(const char* data, float scale) {
    scale *= resolutionScale;
    
    DHJson* root = Json_create(data);
    DHSkeletonData* skeletonData = DHSkeletonData::create();
    
    DHJson* skeleton = Json_getItem(root, "skeleton");
    if (skeleton) {
        DHJson* spine = Json_getItem(skeleton, "spine");
        skeletonData->setVersion(spine->valueString);
    }
    
    DHJson* bones = Json_getItem(root, "bones");
    if (bones) {
        skeletonData->createBoneDataArray(bones->size);
        
        int boneIndex = 0;
        for (DHJson* boneMap = bones->child; boneMap; boneMap = boneMap->next) {
            DHBoneData* boneData = skeletonData->createBoneData(boneIndex, Json_getString(boneMap, "name", 0));
            
            const char* parentName = Json_getString(boneMap, "parent", 0);
            boneData->m_parentIndex = parentName ? skeletonData->findBoneIndex(parentName) : -1;
            boneData->m_index = boneIndex++;
            boneData->m_length = Json_getFloat(boneMap, "length", 0) * scale;
            boneData->m_x = Json_getFloat(boneMap, "x", 0) * scale;
            boneData->m_y = Json_getFloat(boneMap, "y", 0) * scale;
            boneData->m_rotation = Json_getFloat(boneMap, "rotation", 0);
            boneData->m_scaleX = Json_getFloat(boneMap, "scaleX", 1);
            boneData->m_scaleY = Json_getFloat(boneMap, "scaleY", 1);
            boneData->m_inheritScale = Json_getInt(boneMap, "inheritScale", 1);
            boneData->m_inheritRotation = Json_getInt(boneMap, "inheritRotation", 1);
            boneData->m_flipX = Json_getInt(boneMap, "flipX", 0);
            boneData->m_flipY = Json_getInt(boneMap, "flipY", 0);
        }
    }
    
    /* IK constraints. */
    DHJson* ik = Json_getItem(root, "ik");
    if (ik) {
        skeletonData->createIkConstraintDataArray(ik->size);
        
        int index = 0;
        for (DHJson* ikMap = ik->child; ikMap; ikMap = ikMap->next) {
            DHJson* boneMap = Json_getItem(ikMap, "bones");
            DHIkConstraintData* ikData = skeletonData->createIkConstraintData(index, Json_getString(ikMap, "name", 0), boneMap->size);
            
            int j = 0;
            for (boneMap = boneMap->child, j = 0; boneMap; boneMap = boneMap->next, ++j) {
                ikData->m_bones[j] = skeletonData->findBone(boneMap->valueString);
            }
            
            const char* targetName = Json_getString(ikMap, "target", 0);
            ikData->m_target = skeletonData->findBone(targetName);
            
            ikData->m_bendDirection = Json_getInt(ikMap, "bendPositive", 1) ? 1 : -1;
            ikData->m_mix = Json_getFloat(ikMap, "mix", 1);
            ikData->m_index = index++;
        }
    }
    
    DHJson* slots = Json_getItem(root, "slots");
	if (slots) {
        int slotIndex = 0;
        skeletonData->createSlotDataArray(slots->size);
		for (DHJson* slotMap = slots->child; slotMap; slotMap = slotMap->next) {
			DHSlotData* slotData = skeletonData->createSlotData(slotIndex, Json_getString(slotMap, "name", 0), Json_getString(slotMap, "attachment", 0));
            
            slotData->m_index = slotIndex++;
            slotData->m_boneIndex = skeletonData->findBoneIndex(Json_getString(slotMap, "bone", 0));
			const char* color = Json_getString(slotMap, "color", 0);
			if (color) {
				slotData->m_r = toColor(color, 0);
				slotData->m_g = toColor(color, 1);
				slotData->m_b = toColor(color, 2);
				slotData->m_a = toColor(color, 3);
			}
            else {
                slotData->m_r = slotData->m_g = slotData->m_b = slotData->m_a = 1.0f;
            }
            slotData->m_blendMode = SpineBlendType::sbt_none;
            
            //Backward compatibility
            if (Json_getInt(slotMap, "additive", 0)) {
                slotData->m_blendMode = SpineBlendType::sbt_additive;
            }
            
            const char* blend = Json_getString(slotMap, "blend", 0);
            if (blend) {
                if (!strcmp(blend, "additive")) {
                    slotData->m_blendMode = SpineBlendType::sbt_additive;
                }
                else if (strcmp(blend, "multiply") == 0) {
                    slotData->m_blendMode = SpineBlendType::sbt_multiply;
                }
                else if (strcmp(blend, "screen") == 0) {
                    slotData->m_blendMode = SpineBlendType::sbt_screen;
                }
            }
		}
	}
    
    DHJson* skins = Json_getItem(root, "skins");
    if (skins) {
        for (DHJson* skinMap = skins->child; skinMap; skinMap = skinMap->next) {
            DHSkin* skin = skeletonData->createSkin(skinMap->name, skinMap->size);
            
            int skinIndex = 0;
            for (DHJson* slotMap = skinMap->child; slotMap; slotMap = slotMap->next) {
                
                skin->createSkinSlot(skinIndex, skeletonData->findSlotIndex(slotMap->name));

                for (DHJson* attachmentsMap = slotMap->child; attachmentsMap; attachmentsMap = attachmentsMap->next) {
                    
                    const char* attachmentName = attachmentsMap->name;
                    const char* actualAttachmentName = Json_getString(attachmentsMap, "name", attachmentName);
                    const char* filePathName = Json_getString(attachmentsMap, "path", actualAttachmentName);
                    
                    const char* typeString = Json_getString(attachmentsMap, "type", "region");
                    
                    char fullFilePath[256];
                    
                    sprintf(fullFilePath, "%s.png", filePathName);
                    
                    DHAttachment* attachment = nullptr;
                    
                    if (strcmp(typeString, "region") == 0) {
                        
                        DHRegionAttachment::RegionData regionData;
                        
                        const char* color = Json_getString(attachmentsMap, "color", 0);
                        if (color) {
                            regionData.r = toColor(color, 0);
                            regionData.g = toColor(color, 1);
                            regionData.b = toColor(color, 2);
                            regionData.a = toColor(color, 3);
                        }
                        else {
                            regionData.r = regionData.g = regionData.b = regionData.a = 1.0f;
                        }
                        
                        regionData.x = Json_getFloat(attachmentsMap, "x", 0) * scale;
                        regionData.y = Json_getFloat(attachmentsMap, "y", 0) * scale;
                        regionData.scaleX = Json_getFloat(attachmentsMap, "scaleX", 1);
                        regionData.scaleY = Json_getFloat(attachmentsMap, "scaleY", 1);
                        regionData.rotation = Json_getFloat(attachmentsMap, "rotation", 0);
                        regionData.width = Json_getFloat(attachmentsMap, "width", 32) * scale;
                        regionData.height = Json_getFloat(attachmentsMap, "height", 32) * scale;
                        
                        attachment = DHRegionAttachment::createWithSpriteFrameName(fullFilePath, regionData);
#if DH_SPINE_RELEASE == 0
                        if (!attachment) {
                            if (relativeFilePath) {
                                sprintf(fullFilePath, "%s%s.png",relativeFilePath, filePathName);
                            }
                            attachment = DHRegionAttachment::createWithFile(fullFilePath, regionData);
                        }
#endif
                    }
                    else if (strcmp(typeString, "mesh") == 0) {
                        DHMeshAttachment::MeshData meshData;
                        
                        DHJson* entry = Json_getItem(attachmentsMap, "vertices");
                        meshData.verticesCount = entry->size;
                        meshData.vertices = new float[meshData.verticesCount];
                        
                        int i = 0;
                        for (entry = entry->child; entry; entry = entry->next, ++i) {
                            meshData.vertices[i] = entry->valueFloat * scale;
                        }
                        
                        entry = Json_getItem(attachmentsMap, "triangles");
                        meshData.trianglesCount = entry->size;
                        meshData.triangles = new int[meshData.trianglesCount];
                        for (entry = entry->child, i = 0; entry; entry = entry->next, ++i) {
                            meshData.triangles[i] = entry->valueInt;
                        }
                        
                        entry = Json_getItem(attachmentsMap, "uvs");
                        meshData.regionUVs = new float[entry->size];
                        for (entry = entry->child, i = 0; entry; entry = entry->next, ++i) {
                            meshData.regionUVs[i] = entry->valueFloat;
                        }
                        
                        const char* color = Json_getString(attachmentsMap, "color", 0);
                        if (color) {
                            meshData.r = toColor(color, 0);
                            meshData.g = toColor(color, 1);
                            meshData.b = toColor(color, 2);
                            meshData.a = toColor(color, 3);
                        }
                        else {
                            meshData.r = meshData.g = meshData.b = meshData.a = 1.0f;
                        }
                        
                        meshData.hullLength = Json_getInt(attachmentsMap, "hull", 0);
                        
                        entry = Json_getItem(attachmentsMap, "edges");
                        if (entry) {
                            meshData.edgesCount = entry->size;
                            meshData.edges = new int[meshData.edgesCount];
                            for (entry = entry->child, i = 0; entry; entry = entry->next, ++i) {
                                meshData.edges[i] = entry->valueInt;
                            }
                        }
                        
                        meshData.width = Json_getFloat(attachmentsMap, "width", 32) * scale;
                        meshData.height = Json_getFloat(attachmentsMap, "height", 32) * scale;
                        
                        attachment = DHMeshAttachment::createWithSpriteFrameName(fullFilePath, meshData);
                        
#if DH_SPINE_RELEASE == 0
                        if (!attachment) {
                            if (relativeFilePath) {
                                sprintf(fullFilePath, "%s%s.png",relativeFilePath, filePathName);
                            }
                            attachment = DHMeshAttachment::createWithFile(fullFilePath, meshData);
                        }
#endif
                    }
                    else if (strcmp(typeString, "skinnedmesh") == 0) {
                        DHSkinnedMeshAttachment::SkinnedMeshData skinnedMeshData;
                        
                        DHJson* entry = Json_getItem(attachmentsMap, "uvs");
                        
                        skinnedMeshData.uvsCount = entry->size;
                        skinnedMeshData.regionUVs = new float[skinnedMeshData.uvsCount];
                        
                        int i = 0;
                        for (DHJson* uvs = entry->child; uvs; uvs = uvs->next) {
                            skinnedMeshData.regionUVs[i++] = uvs->valueFloat;
                        }
                        
                        int verticesCount;
                        float* vertices;
                        
                        entry = Json_getItem(attachmentsMap, "vertices");
                        verticesCount = entry->size;
                        vertices = new float[verticesCount];
                        for (entry = entry->child, i = 0; entry; entry = entry->next, ++i) {
                            vertices[i] = entry->valueFloat;
                        }
                        
                        skinnedMeshData.bonesCount = 0;
                        skinnedMeshData.weightsCount = 0;

                        for (i = 0; i < verticesCount;) {
                            int bonesCount = (int)vertices[i];
                            skinnedMeshData.bonesCount += bonesCount + 1;
                            skinnedMeshData.weightsCount += bonesCount * 3;
                            i += 1 + bonesCount * 4;
                        }
                        skinnedMeshData.bones = new int[skinnedMeshData.bonesCount];
                        skinnedMeshData.weights = new float[skinnedMeshData.weightsCount];
                        
                        for (int si = 0, b = 0, w = 0; si < verticesCount;) {
                            int bonesCount = (int)vertices[si++];
                            skinnedMeshData.bones[b++] = bonesCount;
                            for (int nn = si + bonesCount * 4; si < nn; si += 4, ++b, w += 3) {
                                skinnedMeshData.bones[b] = (int)vertices[si];
                                skinnedMeshData.weights[w] = vertices[si + 1] * scale;
                                skinnedMeshData.weights[w + 1] = vertices[si + 2] * scale;
                                skinnedMeshData.weights[w + 2] = vertices[si + 3];
                            }
                        }
                        
                        delete [] vertices;
                        
                        entry = Json_getItem(attachmentsMap, "triangles");
                        skinnedMeshData.trianglesCount = entry->size;
                        skinnedMeshData.triangles = new int[skinnedMeshData.trianglesCount];
                        for (entry = entry->child, i = 0; entry; entry = entry->next, ++i) {
                            skinnedMeshData.triangles[i] = entry->valueInt;
                        }
                        
                        const char* color = Json_getString(attachmentsMap, "color", 0);
                        if (color) {
                            skinnedMeshData.r = toColor(color, 0);
                            skinnedMeshData.g = toColor(color, 1);
                            skinnedMeshData.b = toColor(color, 2);
                            skinnedMeshData.a = toColor(color, 3);
                        }
                        else {
                            skinnedMeshData.r = skinnedMeshData.g = skinnedMeshData.b = skinnedMeshData.a = 1.0f;
                        }
                        
                        skinnedMeshData.hullLength = Json_getInt(attachmentsMap, "hull", 0);
                        
                        entry = Json_getItem(attachmentsMap, "edges");
                        if (entry) {
                            skinnedMeshData.edgesCount = entry->size;
                            skinnedMeshData.edges = new int[skinnedMeshData.edgesCount];
                            for (entry = entry->child, i = 0; entry; entry = entry->next, ++i) {
                                skinnedMeshData.edges[i] = entry->valueInt;
                            }
                        }
                        
                        skinnedMeshData.width = Json_getFloat(attachmentsMap, "width", 32) * scale;
                        skinnedMeshData.height = Json_getFloat(attachmentsMap, "height", 32) * scale;
                        
                        attachment = DHSkinnedMeshAttachment::createWithSpriteFrameName(fullFilePath, skinnedMeshData);
                        
#if DH_SPINE_RELEASE == 0
                        if (!attachment) {
                            if (relativeFilePath) {
                                sprintf(fullFilePath, "%s%s.png",relativeFilePath, filePathName);
                            }
                            attachment = DHSkinnedMeshAttachment::createWithFile(fullFilePath, skinnedMeshData);
                        }
#endif
                    }
					else if (strcmp(typeString, "boundingbox") == 0) {
                        DHJson* verticesArray = Json_getItem(attachmentsMap, "vertices");
                        DHBoundingBoxAttachment* bdAttachment = DHBoundingBoxAttachment::create();
                        float* vertices = bdAttachment->createVertices(verticesArray->size);
                        int i = 0;
                        for (DHJson* vertex = verticesArray->child; vertex; vertex = vertex->next) {
                            vertices[i++] = vertex->valueFloat * scale;
                        }
                        
                        attachment = bdAttachment;
                    }
                    
                    skin->addAttachment(skinIndex, attachmentName, attachment);
                }
                ++skinIndex;
            }
            skin->updateInfo();
        }
    }
    
    DHJson* events = Json_getItem(root, "events");
	if (events) {
		for (DHJson* eventMap = events->child; eventMap; eventMap = eventMap->next) {
            DHEvent* event = skeletonData->createEvent(eventMap->name);
            event->name = eventMap->name;
            event->intValue = Json_getInt(eventMap, "int", 0);
			event->floatValue = Json_getFloat(eventMap, "float", 0);
			event->stringValue = Json_getString(eventMap, "string", "");
		}
	}
    
    DHJson* animations = Json_getItem(root, "animations");
	if (animations) {
		for (DHJson* animationMap = animations->child; animationMap; animationMap = animationMap->next) {
			loadAnimation(animationMap, skeletonData, scale);
        }
	}
    
    Json_dispose(root);
    
    return skeletonData;
}

void DHSpineLoader::loadCurve(DHJson *root, DHCurveTimeline *frame) {
    DHJson* curve = Json_getItem(root, "curve");
	if (!curve) {
        frame->setLinear();
        return;
    }
	if (curve->type == Json_String && strcmp(curve->valueString, "stepped") == 0) {
		frame->setStepped();
    }
	else if (curve->type == Json_Array) {
		DHJson* child0 = curve->child;
		DHJson* child1 = child0->next;
		DHJson* child2 = child1->next;
		DHJson* child3 = child2->next;
        frame->setCurve(child0->valueFloat, child1->valueFloat, child2->valueFloat, child3->valueFloat);
	}
}

void DHSpineLoader::loadAnimation(DHJson* root, DHSkeletonData* skeletonData, float scale) {
    DHJson* bones = Json_getItem(root, "bones");
	DHJson* slots = Json_getItem(root, "slots");
    DHAnimationData* animation = skeletonData->createAnimation(root->name, bones ? bones->size : 0, slots ? slots->size : 0);
    animation->setName(root->name);
    
    if (bones) {
        int index = 0;
        for (DHJson* boneMap = bones->child; boneMap; boneMap = boneMap->next) {
            DHBoneTransform* bt = animation->createBoneTransform(index++, skeletonData->findBoneIndex(boneMap->name));
            for (DHJson* timelineArray = boneMap->child; timelineArray; timelineArray = timelineArray->next) {
                DHJson* frame;
                unsigned int frameIndex = 0, frameCount = timelineArray->size;
                
                if (strcmp(timelineArray->name, "rotate") == 0) {
                    bt->createRotationTimeLine(frameCount);
                    for (frame = timelineArray->child; frame; frame = frame->next) {
                        DHRotateKeyFrame* rotate = bt->createRotationKeyFrame(frameIndex++);
                        rotate->time = Json_getFloat(frame, "time", 0);
                        rotate->angle = Json_getFloat(frame, "angle", 0);
                        loadCurve(frame, rotate);
                    }
                } else if(strcmp(timelineArray->name, "translate") == 0) {
                    bt->createTranslationTimeLine(frameCount);
                    for (frame = timelineArray->child; frame; frame = frame->next) {
                        DHTranslateKeyFrame* translate = bt->createTranslationKeyFrame(frameIndex++);
                        translate->time = Json_getFloat(frame, "time", 0);
                        translate->x = Json_getFloat(frame, "x", 0) * scale;
                        translate->y = Json_getFloat(frame, "y", 0) * scale;
                        loadCurve(frame, translate);
                    }
                } else if(strcmp(timelineArray->name, "scale") == 0) {
                    bt->createScaleTimeLine(frameCount);
                    for (frame = timelineArray->child; frame; frame = frame->next) {
                        DHScaleKeyFrame* scaleKeyFrame = bt->createScaleKeyFrame(frameIndex++);
                        scaleKeyFrame->time = Json_getFloat(frame, "time", 0);
                        scaleKeyFrame->scaleX = Json_getFloat(frame, "x", 0);
                        scaleKeyFrame->scaleY = Json_getFloat(frame, "y", 0);
                        loadCurve(frame, scaleKeyFrame);
                    }
                } else if (strcmp(timelineArray->name, "flipX") == 0 || strcmp(timelineArray->name, "flipY") == 0) {
                    bool x = strcmp(timelineArray->name, "flipX") == 0;
                    const char* field = x ? "x" : "y";
                    bt->createFlipTimeLine(frameCount, x);
                    for (frame = timelineArray->child; frame; frame = frame->next) {
                        DHFlipKeyFrame* flip = bt->createFlipKeyFrame(frameIndex++, x);
                        flip->time = Json_getFloat(frame, "time", 0);
                        flip->flip = Json_getInt(frame, field, 0);
                    }
                }
            }
        }
    }
    
    if (slots) {
        int index = 0;
        for (DHJson* slotMap = slots->child ; slotMap; slotMap = slotMap->next) {
            DHSlotTransform* st = animation->createSlotTransform(index++, skeletonData->findSlotIndex(slotMap->name));
            for (DHJson* timelineArray = slotMap->child; timelineArray; timelineArray = timelineArray->next) {
                DHJson* frame;
                unsigned int frameIndex = 0;
                
                if (strcmp(timelineArray->name, "color") == 0) {
                    st->createColorTimeline(timelineArray->size);
                    for (frame = timelineArray->child; frame; frame = frame->next) {
                        DHColorKeyFrame* color = st->createColorKeyFrame(frameIndex++);
                        const char* s = Json_getString(frame, "color", 0);
                        color->time = Json_getFloat(frame, "time", 0);
                        color->r = toColor(s, 0);
                        color->g = toColor(s, 1);
                        color->b = toColor(s, 2);
                        color->a = toColor(s, 3);
                        loadCurve(frame, color);
                    }
                    
                } else if (strcmp(timelineArray->name, "attachment") == 0) {
                    st->createAttachmentTimeline(timelineArray->size);
                    for (frame = timelineArray->child; frame; frame = frame->next) {
                        DHAttachmentKeyFrame* attachment = st->createAttachmentKeyFrame(frameIndex++, Json_getString(frame, "name", 0));
                        attachment->time = Json_getFloat(frame, "time", 0);
                    }
                }
            }
        }
    }
    
    DHJson* ik = Json_getItem(root, "ik");
    if (ik) {
        animation->createIkConstraintTimeline(ik->size);
        
        int index = 0;
        for (DHJson* ikMap = ik->child; ikMap; ikMap = ikMap->next) {
            DHIkConstraintData* ikConstraint = skeletonData->findIkConstraint(ikMap->name);
            DHIkConstraintTransform* ikTransform = animation->createIkConstraintTransform(index++, ikConstraint->m_index);
            ikTransform->createIkConstraintTimeline(ikMap->size);
            
            unsigned int frameIndex = 0;
            for (DHJson* frame = ikMap->child; frame; frame = frame->next) {
                DHIkConstraintKeyFrame* keyFrame = ikTransform->createIkConstraintKeyFrame(frameIndex++);
                
                keyFrame->time = Json_getFloat(frame, "time", 0);
                keyFrame->mix = Json_getFloat(frame, "mix", 0) - ikConstraint->m_mix;
                keyFrame->bendPositive = Json_getInt(frame, "bendPositive", 1) ? 1 : -1;
                
                loadCurve(frame, keyFrame);
            }
        }
    }
    
    /* FFD timelines. */
    DHJson* ffd = Json_getItem(root, "ffd");
    if (ffd) {
        int timelinesCount = 0;
        for (DHJson* ffdMap = ffd->child; ffdMap; ffdMap = ffdMap->next) {
            for (DHJson* slotMap = ffdMap->child; slotMap; slotMap = slotMap->next) {
                timelinesCount += slotMap->size;
            }
        }
        animation->createFFDTimeline(timelinesCount);
        
        //exception handling
        bool exceptionBreak = false;
        
        int index = 0;
        for (DHJson* ffdMap = ffd->child; ffdMap && !exceptionBreak; ffdMap = ffdMap->next) {
            DHSkin* skin = skeletonData->findSkin(ffdMap->name);
            
            for (DHJson* slotMap = ffdMap->child; slotMap && !exceptionBreak; slotMap = slotMap->next) {
                int slotIndex = skeletonData->findSlotIndex(slotMap->name);
                if (slotIndex < 0) {
                    CCLOG("!!dhspine : Fatal Errormiss slot not find! %s", slotMap->name);
                    exceptionBreak = true;
                    break;
                }
                
                for (DHJson* timelineArray = slotMap->child; timelineArray; timelineArray = timelineArray->next) {
                    unsigned int verticesCount = 0;
                    DHAttachment* attachment = skin->getAttachment(slotIndex, timelineArray->name);
                    
                    if (!attachment) {
                        exceptionBreak = true;
                        break;
                    }
                    
                    if (attachment->getType() == DHAttachmentType::at_mesh) {
                        verticesCount = ((DHMeshAttachment*)attachment)->getData().verticesCount;
                    }
                    else if (attachment->getType() == DHAttachmentType::at_skinned_mesh) {
                        verticesCount = ((DHSkinnedMeshAttachment*)attachment)->getData().weightsCount / 3 * 2;
                    }
                    
                    DHFFDTransform* ffdTransform = animation->createFFDTransform(index++, slotIndex, attachment, verticesCount);
                    ffdTransform->createFFDTimeline(timelineArray->size);
                    
                    unsigned int frameIndex = 0;
                    for (DHJson* frame = timelineArray->child; frame; frame = frame->next, ++frameIndex) {
                        DHJson* vertices = Json_getItem(frame, "vertices");
                        DHFFDKeyFrame* keyFrame = ffdTransform->createFFDKeyFrame(frameIndex);
                        
                        if (!vertices) {
                            if (attachment->getType() == DHAttachmentType::at_mesh) {
                                memcpy(keyFrame->vertices, ((DHMeshAttachment*)attachment)->getData().vertices, sizeof(float) * verticesCount);
                            }
                            else {
                                memset(keyFrame->vertices, 0, sizeof(float) * verticesCount);
                            }
                        }
                        else {
                            int start = Json_getInt(frame, "offset", 0);
                            memset(keyFrame->vertices, 0, sizeof(float) * start);
                            
                            int v = start;
                            for (DHJson* vertex = vertices->child; vertex; vertex = vertex->next, ++v) {
                                keyFrame->vertices[v] = vertex->valueFloat * scale;
                            }
                            
                            memset(keyFrame->vertices + v, 0, sizeof(float) * (verticesCount - v));
                            if (attachment->getType() == DHAttachmentType::at_mesh) {
                                float* meshVertices = ((DHMeshAttachment*)attachment)->getData().vertices;
                                for (v = 0; v < verticesCount; ++v) {
                                    keyFrame->vertices[v] += meshVertices[v];
                                }
                            }
                        }
                        
                        keyFrame->time = Json_getFloat(frame, "time", 0);
                        loadCurve(frame, keyFrame);
                    }
                }
            }
        }
        
        if (exceptionBreak) {
            animation->freeFFDTimeline(index);
        }
    }
    
    DHJson* events = Json_getItem(root, "events");
    if (events) {
        int frameIndex = 0;
        animation->createEventTimeline(events->size);
        for (DHJson* frame = events->child; frame; frame = frame->next) {
            DHEventsKeyFrame* keyFrame = animation->createEventsKeyFrame(frameIndex++);
            DHEvent* data = keyFrame->data;
            
            data->name = Json_getString(frame, "name", 0);
            DHEvent* defaultData = skeletonData->findEvent(data->name.c_str());
            
            data->intValue = Json_getInt(frame, "int", defaultData->intValue);
            data->floatValue = Json_getFloat(frame, "float", defaultData->floatValue);
            data->stringValue = Json_getString(frame, "string", defaultData->stringValue.c_str());
            
            keyFrame->time = Json_getFloat(frame, "time", 0);
            
            if (data->name == "sound") {//special
                skeletonData->addSoundToSet(data->stringValue);
            }
        }
    }
    
    DHJson* drawOrder = Json_getItem(root, "draworder");
    if (drawOrder) {
        int frameIndex = 0;
        animation->createDrawOrderTimeLine(drawOrder->size);
        for (DHJson* frame = drawOrder->child; frame; frame = frame->next) {
            DHDrawOrderKeyFrame* keyFrame = nullptr;
            DHJson* offsets = Json_getItem(frame, "offsets");
            if (offsets) {
                int slotCount = skeletonData->getSlotCount();
				int* unchanged = new int[slotCount - offsets->size];
				int originalIndex = 0, unchangedIndex = 0;
                
                keyFrame = animation->createDrawOrderKeyFrame(frameIndex++, slotCount);
                int *drawOrderArry = keyFrame->drawOrders;
                memset(drawOrderArry, -1, sizeof(int) * slotCount);
                
                for (DHJson* offsetMap = offsets->child; offsetMap; offsetMap = offsetMap->next) {
                    int slotIndex = skeletonData->findSlotIndex(Json_getString(offsetMap, "slot", 0));
                    /* Collect unchanged items. */
                    while (originalIndex != slotIndex) {
                        unchanged[unchangedIndex++] = originalIndex++;
                    }
                    /* Set changed items. */
					drawOrderArry[originalIndex + Json_getInt(offsetMap, "offset", 0)] = originalIndex;
					++originalIndex;
                }
                /* Collect remaining unchanged items. */
                while (originalIndex < slotCount) {
					unchanged[unchangedIndex++] = originalIndex++;
                }
                for (int i = slotCount - 1; i >= 0; i--) {
					if (drawOrderArry[i] == -1) {
                        drawOrderArry[i] = unchanged[--unchangedIndex];
                    }
                }
                delete [] unchanged;
            }
            else {
                keyFrame = animation->createDrawOrderKeyFrame(frameIndex++, 0);
            }
            keyFrame->time = Json_getFloat(frame, "time", 0);
        }
    }
    
    animation->updateInfo();
}

DHSkeletonData* DHSpineLoader::loadSkeletonData(const char* path, float scale) {
    ssize_t dataLen = 0;
    char* data = reinterpret_cast<char*>(FileUtils::getInstance()->getFileData(path, "rb", &dataLen));
    
    if(data) {
        if (m_xxteaEnabled && strncmp(data, m_xxteaSign, m_xxteaSignLen) == 0)
        {
            // decrypt XXTEA
            xxtea_long len = 0;
            unsigned char* result = xxtea_decrypt((unsigned char*)data + m_xxteaSignLen,
                                                  (xxtea_long)dataLen - m_xxteaSignLen,
                                                  (unsigned char*)m_xxteaKey,
                                                  (xxtea_long)m_xxteaKeyLen,
                                                  &len);
            
            unsigned char* unpackedData = nullptr;
            ssize_t unpackedLen = 0;
            
            if (ZipUtils::isCCZBuffer(result, len))
            {
                unpackedLen = ZipUtils::inflateCCZBuffer(result, len, &unpackedData);
                free(result);
            }
            else if (ZipUtils::isGZipBuffer(result, len))
            {
                unpackedLen = ZipUtils::inflateMemory(const_cast<unsigned char*>(result), len, &unpackedData);
                free(result);
            }
            else
            {
                unpackedData = const_cast<unsigned char*>(result);
                unpackedLen = len;
            }
            
            DHSkeletonData* skeletonData = loadSkeletonFromData((const char*)unpackedData, scale);
            skeletonData->setName(path);
            
            free(unpackedData);
            delete[] data;
            
            return skeletonData;
        }
        else {
            DHSkeletonData* skeletonData = loadSkeletonFromData(data, scale);
            skeletonData->setName(path);
            
            delete[] data;
            
            return skeletonData;
        }
    }
    return nullptr;
}

void DHSpineLoader::cleanupXXTEAKeyAndSign()
{
    if (m_xxteaKey)
    {
        free(m_xxteaKey);
        m_xxteaKey = nullptr;
        m_xxteaKeyLen = 0;
    }
    if (m_xxteaSign)
    {
        free(m_xxteaSign);
        m_xxteaSign = nullptr;
        m_xxteaSignLen = 0;
    }
}

void DHSpineLoader::setXXTEAKeyAndSign(const char *key, int keyLen, const char *sign, int signLen)
{
    cleanupXXTEAKeyAndSign();
    
    if (key && keyLen && sign && signLen)
    {
        m_xxteaKey = (char*)malloc(keyLen);
        memcpy(m_xxteaKey, key, keyLen);
        m_xxteaKeyLen = keyLen;
        
        m_xxteaSign = (char*)malloc(signLen);
        memcpy(m_xxteaSign, sign, signLen);
        m_xxteaSignLen = signLen;
        
        m_xxteaEnabled = true;
    }
    else
    {
        m_xxteaEnabled = false;
    }
}

NS_CC_END