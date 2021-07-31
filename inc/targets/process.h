#pragma once

#include <string>
#include <string_view>
#include <nlohmann/json.hpp>

#include "file.h"

namespace OC {

    struct Process
    {
        int pid;
        std::string name;
        std::string cwd;
        File* executable;
        Process* parent;
        std::string commandLine;
    };

    void to_json(nlohmann::json& j, const Process& p);
    void from_json(const nlohmann::json& j, Process& p);

}
