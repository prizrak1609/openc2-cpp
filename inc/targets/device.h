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

}
