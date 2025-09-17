#ifndef LVE_PIPELINE_H
#define LVE_PIPELINE_H

#include <string>
#include <vector>

namespace lve {
    class LvePipeline {
    public:
        LvePipeline(const std::string &vertFilepath, const std::string &fragFilepath);

    private:
        static std::vector<char> readFile(const std::string& filepath);

        static void createGraphicsPipeline(const std::string &vertFilepath, const std::string &fragFilepath);
    };
}


#endif
