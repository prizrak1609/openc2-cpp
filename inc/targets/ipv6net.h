#pragma once

#include <string>
#include <string_view>
#include <nlohmann/json.hpp>

namespace OC {

    struct Ipv6Net
    {
        std::string ipv6Net;
    };

    void to_json(nlohmann::json& j, const Ipv6Net& p);
    void from_json(const nlohmann::json& j, Ipv6Net& p);

}
