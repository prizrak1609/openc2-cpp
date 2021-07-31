#pragma once

#include <string>
#include <string_view>
#include <nlohmann/json.hpp>

#include "target.h"
#include "args.h"

namespace OC {

    struct OpenC2Message {
            std::string action;
            Target *target = nullptr;
            Args *args = nullptr;
            std::string commandId;
    };

    void to_json(nlohmann::json& j, const OpenC2Message& p);
    void from_json(const nlohmann::json& j, OpenC2Message& p);

}
