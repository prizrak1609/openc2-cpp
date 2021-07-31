#pragma once

#include <string>
#include <string_view>
#include <nlohmann/json.hpp>

namespace OC {

    struct MacAddress
    {
        std::string macAddress;
    };

    void to_json(nlohmann::json& j, const MacAddress& p);
    void from_json(const nlohmann::json& j, MacAddress& p);

}
