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

    void to_json(nlohmann::json& j, const Ipv6Connection& p);
    void from_json(const nlohmann::json& j, Ipv6Connection& p);

}
