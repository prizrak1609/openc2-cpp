#pragma once

#include <string>
#include <string_view>

#include "Json.h"

namespace OC {

    struct Ipv4Connection
    {
        std::string srcAddr;
        int srcPort;
        std::string dstAddr;
        int dstPort;
        std::string protocol;
    };

    namespace JSON {
        template<>
        std::string toJson(const Ipv4Connection& item);

        template<>
        Ipv4Connection fromJson(std::string_view json);
    }

}


