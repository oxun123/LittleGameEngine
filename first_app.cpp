#include "first_app.h"

#include <GLFW/glfw3.h>

namespace lve {
    void FirstApp::run() {
        while (!lveWindow.shouldClose()) {
            glfwPollEvents();
        }
    }
}
