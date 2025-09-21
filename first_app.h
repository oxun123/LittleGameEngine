#ifndef FIRST_APP_H
#define FIRST_APP_H

#include "lve_window.h"
#include "lve_pipeline.h"

namespace lve {
    class FirstApp {
    public:
        static constexpr int HEIGHT = 800;
        static constexpr int WIDTH = 600;

        void run();

    private:
        LveWindow lveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
        LveDevice lveDevice{lveWindow};
        LvePipeline lvePipeline{
            lveDevice,
            "D:/LittleGameEngine/shaders/simple_vert.spv",
            "D:/LittleGameEngine/shaders/simple_frag.spv",
            LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)
        };
    };
}

#endif