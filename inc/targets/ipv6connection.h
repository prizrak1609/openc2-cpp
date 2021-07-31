#pragma once

#include <string>
#include <string_view>

#include "Json.h"

namespace OC {

    struct Ipv6Connection
    {
        std::string srcAddr;
        int srcPort;
        std::string dstAddr;
        int dstPort;
        std::string protocol;
    };

    namespace JSON {
        template<>
        std::string toJson(const Ipv6Connection& item);

        template<>
        Ipv6Connection fromJson(std::string_view json);
    }

}
