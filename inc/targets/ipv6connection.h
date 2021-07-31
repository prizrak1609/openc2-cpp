#pragma once

#include <string>
#include <string_view>
#include <nlohmann/json.hpp>

namespace OC {

    struct Ipv6Connection
    {
        std::string srcAddr;
        int srcPort;
        std::string dstAddr;
        int dstPort;
        std::string protocol;
    };

}
