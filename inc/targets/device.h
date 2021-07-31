#pragma once

#include <string>

#include "Json.h"

namespace OC {

    struct Device
    {
            std::string hostname;
            std::string idnHostname;
            std::string deviceId;
    };

    namespace JSON {
        template<>
        std::string toJson(const Device& item);

        template<>
        Device fromJson(std::string_view json);
    }

}
