#pragma once

#include <string>
#include <string_view>

#include "Json.h"

namespace OC {

    struct MacAddress
    {
        std::string macAddress;
    };

    namespace JSON {
        template<>
        std::string toJson(const MacAddress& item);

        template<>
        MacAddress fromJson(std::string_view json);
    }

}
