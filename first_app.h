#ifndef FIRST_APP_H
#define FIRST_APP_H

#include "lve_device.h"
#include "lve_pipeline.h"
#include "lve_swap_chain.h"
#include "lve_window.h"

#include <memory>
#include <vector>

namespace lve {
    class FirstApp {
    public:
        static constexpr int HEIGHT = 800;
        static constexpr int WIDTH = 600;

        FirstApp();

        ~FirstApp();

        FirstApp(const FirstApp &) = delete;

        FirstApp &operator=(const FirstApp &) = delete;

        void run();

    private:
        void createPipelineLayout();
        void createPipeline();
        void createCommandBuffers();
        void drawFrame();

        LveWindow lveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
        LveDevice lveDevice{lveWindow};
        // LvePipeline lvePipeline{
        //     lveDevice,
        //     "D:/LittleGameEngine/shaders/simple_vert.spv",
        //     "D:/LittleGameEngine/shaders/simple_frag.spv",
        //     LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)
        // };

        LveSwapChain lveSwapChain{lveDevice, lveWindow.getExtent()};
        std::unique_ptr<LvePipeline> lvePipeline;
        VkPipelineLayout pipelineLayout;
        std::vector<VkCommandBuffer> commandBuffers;
    };
}

#endif