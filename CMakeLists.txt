cmake_minimum_required(VERSION 4.0)
project(LittleGameEngine)

set(CMAKE_CXX_STANDARD 17)
set(GLFW_INCLUDE_DIR "D:/vulkan_example/glfw-3.4.bin.WIN64/include")
set(GLFW_LIBRARY "D:/vulkan_example/glfw-3.4.bin.WIN64/lib-mingw-w64/libglfw3.a")

find_package(Vulkan REQUIRED)

add_executable(LittleGameEngine main.cpp
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
        simple_render_system.h
        simple_render_system.cpp
        lve_gravity_system.h
)

target_include_directories(LittleGameEngine PRIVATE
        ${Vulkan_INCLUDE_DIRS}
        ${GLFW_INCLUDE_DIR}
        shaders
)

target_link_libraries(LittleGameEngine PRIVATE
        ${Vulkan_LIBRARIES}
        ${GLFW_LIBRARY}
        opengl32
        gdi32
        user32
        shell32
)