#include "lve_pipeline.h"

#include <cassert>
#include <fstream>
#include <iostream>
#include <stdexcept>

namespace lve {
    LvePipeline::LvePipeline(
        LveDevice &device,
        const std::string &vertFilepath,
        const std::string &fragFilepath,
        const PipelineConfigInfo &configInfo)
        : lveDevice{device} {
        createGraphicsPipeline(vertFilepath, fragFilepath, configInfo);
    }

    LvePipeline::~LvePipeline() {
        vkDestroyShaderModule(lveDevice.device(), vertShaderModule, nullptr);
        vkDestroyShaderModule(lveDevice.device(), fragShaderModule, nullptr);
        vkDestroyPipeline(lveDevice.device(), graphicsPipeline, nullptr);
    }

    std::vector<char> LvePipeline::readFile(const std::string &filepath) {
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

    void LvePipeline::createGraphicsPipeline(
        const std::string &vertFilepath,
        const std::string &fragFilepath,
        const PipelineConfigInfo &configInfo) {
        const auto vertCode = readFile(vertFilepath);
        const auto fragCode = readFile(fragFilepath);

        std::cout << "Vertex shaders code size: " << vertCode.size() << " bytes\n";
        std::cout << "Fragment shaders code size: " << fragCode.size() << " bytes\n";
    }


    void LvePipeline::createShaderModule(const std::vector<char> &code, VkShaderModule *shaderModule) {
        VkShaderModuleCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        createInfo.codeSize = code.size();
        createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

        if (vkCreateShaderModule(lveDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS) {
            throw std::runtime_error("failed to create shader module");
        }
    }

    PipelineConfigInfo LvePipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height) {
        PipelineConfigInfo configInfo{};

        return configInfo;
    }

}