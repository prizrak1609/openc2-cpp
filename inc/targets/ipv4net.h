#pragma once

#include <string>
#include <string_view>

#include "Json.h"

namespace OC {

    struct Ipv4Net
    {
        std::string ipv4Net;
    };

    namespace JSON {
        template<>
        std::string toJson(const Ipv4Net& item);

        template<>
        Ipv4Net fromJson(std::string_view json);
    }

}
