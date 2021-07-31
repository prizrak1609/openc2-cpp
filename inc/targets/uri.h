#pragma once

#include <string>
#include <nlohmann/json.hpp>

namespace OC {

    struct URI
    {
        std::string uri;
    };

    void to_json(nlohmann::json& j, const URI& p);
    void from_json(const nlohmann::json& j, URI& p);

}
