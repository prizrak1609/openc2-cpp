#pragma once

#include <string>
#include <string_view>
#include <nlohmann/json.hpp>

namespace OC {

    struct Ipv4Net
    {
        std::string ipv4Net;
    };

    void to_json(nlohmann::json& j, const Ipv4Net& p);
    void from_json(const nlohmann::json& j, Ipv4Net& p);

}
