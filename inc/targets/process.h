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
        File executable;
        Process* parent;
        std::string commandLine;
    };

}
