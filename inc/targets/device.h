#pragma once

#include <string>
#include <nlohmann/json.hpp>

namespace OC {

    struct Device
    {
            std::string hostname;
            std::string idnHostname;
            std::string deviceId;
    };

    void to_json(nlohmann::json& j, const Device& p);
    void from_json(const nlohmann::json& j, Device& p);

}
