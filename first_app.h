#ifndef FIRST_APP_H
#define FIRST_APP_H

#include "lve_window.h"

namespace lve {
    class FirstApp {
    public:
        static constexpr int HEIGHT = 800;
        static constexpr int WIDTH = 600;

        void run();

    private:
        LveWindow lveWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
    };
}

#endif