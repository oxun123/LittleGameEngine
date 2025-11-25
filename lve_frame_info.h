#ifndef LVE_FRAMEINFO_H
#define LVE_FRAMEINFO_H

#include "lve_camera.h"
#include <vulkan/vulkan.h>

namespace lve {
    struct FrameInfo {
        int frameIndex;
        float frameTime;
        VkCommandBuffer commandBuffer;
        LveCamera &camera;
    };
}

#endif