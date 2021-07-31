#pragma once

#include <vector>
#include <string>
#include <string_view>
#include <nlohmann/json.hpp>

namespace OC {

    struct Features
    {
        std::vector<std::string> features;
    };

    void to_json(nlohmann::json& j, const Features& p);
    void from_json(const nlohmann::json& j, Features& p);

}
