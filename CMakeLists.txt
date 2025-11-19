cmake_minimum_required(VERSION 3.28)
project(LittleGameEngine)

set(CMAKE_CXX_STANDARD 17)

# Your custom GLFW paths
set(GLFW_INCLUDE_DIR "~/Documents/PERSONAL/glfw-3.4.bin.MACOS/include")
set(GLFW_LIBRARY "$ENV{HOME}/Documents/PERSONAL/glfw-3.4.bin.MACOS/lib-arm64/libglfw3.a")

# Vulkan SDK (MoltenVK)
find_package(Vulkan REQUIRED)

add_executable(LittleGameEngine
        main.cpp
        first_app.h
        lve_window.h
        lve_window.cpp
        first_app.cpp
)

target_include_directories(LittleGameEngine PRIVATE
    ${GLFW_INCLUDE_DIR}
    ${Vulkan_INCLUDE_DIRS}
)

target_link_libraries(LittleGameEngine PRIVATE
        ${GLFW_LIBRARY}
        Vulkan::Vulkan
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
)