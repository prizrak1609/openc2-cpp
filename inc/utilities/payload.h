#pragma once

#include <string>
#include <string_view>
#include <nlohmann/json.hpp>

namespace OC {

    struct Payload {
            std::string url;
            std::string bin;
    };

    void to_json(nlohmann::json& j, const Payload& p);
    void from_json(const nlohmann::json& j, Payload& p);

}
