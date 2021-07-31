#pragma once

#include <string>
#include <string_view>
#include <nlohmann/json.hpp>

#include "Target.h"
#include "Args.h"

namespace OC {

    struct OpenC2Message {
            std::string action;
            Target target;
            Args args;
            std::string commandId;
    };

}
