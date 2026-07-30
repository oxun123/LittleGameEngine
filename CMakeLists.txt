cmake_minimum_required(VERSION 3.28)
project(LittleGameEngine)

set(CMAKE_CXX_STANDARD 17)

set(GLFW_INCLUDE_DIR "$ENV{HOME}/Documents/PERSONAL/glfw-3.4.bin.MACOS/include")
set(GLFW_LIBRARY "$ENV{HOME}/Documents/PERSONAL/glfw-3.4.bin.MACOS/lib-arm64/libglfw3.a")

find_package(glm REQUIRED)
find_package(Vulkan REQUIRED)

add_executable(LittleGameEngine
        main.cpp
        first_app.h
        lve_window.h
        lve_window.cpp
        first_app.cpp
        lve_pipeline.h
        lve_pipeline.cpp
        lve_device.h
        lve_device.cpp
        lve_swap_chain.h
        lve_swap_chain.cpp
        lve_model.h
        lve_model.cpp
        lve_game_object.h
        lve_renderer.h
        lve_renderer.cpp
        systems/simple_render_system.h
        systems/simple_render_system.cpp
        lve_camera.h
        lve_camera.cpp
        keyboard_movement_controller.h
        keyboard_movement_controller.cpp
        tiny_obj_loader.h
        lve_utils.h
        lve_game_object.cpp
        lve_buffer.h
        lve_frame_info.h
        lve_buffer.cpp
        lve_descriptors.cpp
        lve_descriptors.h
        systems/point_light_system.h
        systems/point_light_system.cpp
)

target_include_directories(LittleGameEngine PRIVATE
        ${Vulkan_INCLUDE_DIRS}
        ${GLFW_INCLUDE_DIR}
        shaders
        systems
)

target_link_libraries(LittleGameEngine PRIVATE
        ${GLFW_LIBRARY}
        ${Vulkan_LIBRARIES}
        Vulkan::Vulkan
        glm::glm
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
)