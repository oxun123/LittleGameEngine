#include "first_app.h"

#include "keyboard_movement_controller.h"
#include "lve_camera.h"
#include "simple_render_system.h"

// libs
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>

// std
#include <array>
#include <chrono>

namespace lve {
    FirstApp::FirstApp() { loadGameObjects(); }

    FirstApp::~FirstApp() {
    }

    void FirstApp::run() {
        SimpleRenderSystem simpleRenderSystem{lveDevice, lveRenderer.getSwapChainRenderPass()};
        LveCamera camera{};
        camera.setViewDirection(glm::vec3(0.f), glm::vec3(0.0f, 0.f, 1.f));

        auto viewerObject = LveGameObject::createGameObject();
        KeyboardMovementController cameraController{};

        auto currentTime = std::chrono::high_resolution_clock::now();
        while (!lveWindow.shouldClose()) {
            glfwPollEvents();

            auto newTime = std::chrono::high_resolution_clock::now();
            float frameTime =
                    std::chrono::duration<float, std::chrono::seconds::period>(newTime - currentTime).count();
            currentTime = newTime;

            cameraController.moveInPlaneXZ(lveWindow.getGLFWwindow(), frameTime, viewerObject);
            camera.setViewXYZ(viewerObject.transform.translation, viewerObject.transform.rotation);

            float aspect = lveRenderer.getAspectRatio();
            camera.setPerspectiveProjection(glm::radians(50.f), aspect, 0.1f, 10.0f);
            if (auto commandBuffer = lveRenderer.beginFrame()) {
                lveRenderer.beginSwapChainRenderPass(commandBuffer);
                simpleRenderSystem.renderGameObjects(commandBuffer, gameObjects, camera);
                lveRenderer.endSwapChainRenderPass(commandBuffer);
                lveRenderer.endFrame();
            }
        }

        vkDeviceWaitIdle(lveDevice.device());
    }


    void FirstApp::loadGameObjects() {
        std::shared_ptr<LveModel> lveModel = LveModel::createModelFromFile(lveDevice, "/Users/ferro/Documents/PERSONAL/LittleGameEngine/models/flat_vase.obj");
        auto gameObj = LveGameObject::createGameObject();
        gameObj.model = lveModel;
        gameObj.transform.translation = {0.f, 0.f, 2.5f};
        gameObj.transform.scale = glm::vec3(3.f);
        gameObjects.push_back(std::move(gameObj));
    }
}
