#ifndef LVE_FRAMEINFO_H
#define LVE_FRAMEINFO_H

#include "lve_camera.h"
#include "lve_game_object.h"
#include <vulkan/vulkan.h>

namespace lve {
    struct FrameInfo {
        int frameIndex;
        float frameTime;
        VkCommandBuffer commandBuffer;
        LveCamera &camera;
        VkDescriptorSet globalDescriptorSet;
        LveGameObject::Map &gameObjects;
    };
}

#endif