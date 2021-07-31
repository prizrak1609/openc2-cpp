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

    void to_json(nlohmann::json& j, const OpenC2Message& p);
    void from_json(const nlohmann::json& j, OpenC2Message& p);

}
