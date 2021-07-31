#pragma once

#include <vector>
#include <string>
#include <nlohmann/json.hpp>

namespace OC {

    struct Properties
    {
        std::vector<std::string> properties;
    };

    void to_json(nlohmann::json& j, const Properties& p);
    void from_json(const nlohmann::json& j, Properties& p);

}

