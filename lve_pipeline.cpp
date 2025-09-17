#include "lve_pipeline.h"

#include <fstream>
#include <iostream>
#include <stdexcept>

namespace lve {
    LvePipeline::LvePipeline(const std::string &vertFilepath, const std::string &fragFilepath) {
        createGraphicsPipeline(vertFilepath, fragFilepath);
    }

    std::vector<char> LvePipeline::readFile(const std::string& filepath) {
        std::ifstream file{filepath, std::ios::ate | std::ios::binary};

        if (!file.is_open()) {
            throw std::runtime_error("failed to open file: " + filepath);
        }

        const size_t fileSize = file.tellg();
        std::vector<char> buffer(fileSize);

        file.seekg(0);
        file.read(buffer.data(), fileSize);

        file.close();
        return buffer;
    }

    void LvePipeline::createGraphicsPipeline(const std::string &vertFilepath, const std::string &fragFilepath) {
        const auto vertCode = readFile(vertFilepath);
        const auto fragCode = readFile(fragFilepath);

        std::cout << "Vertex shaders code size: " << vertCode.size() << " bytes\n";
        std::cout << "Fragment shaders code size: " << fragCode.size() << " bytes\n";
    }
}