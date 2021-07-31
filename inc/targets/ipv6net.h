#pragma once

#include <string>
#include <string_view>

#include "Json.h"

namespace OC {

    struct Ipv6Net
    {
        std::string ipv6Net;
    };

    namespace JSON {
        template<>
        std::string toJson(const Ipv6Net& item);

        template<>
        Ipv6Net fromJson(std::string_view json);
    }

}
