#pragma once

#include <string>
#include <string_view>
#include <nlohmann/json.hpp>

namespace OC {

    struct IdnEmailAddress
    {
        std::string idnEmailAddress;
    };

    void to_json(nlohmann::json& j, const IdnEmailAddress& p);
    void from_json(const nlohmann::json& j, IdnEmailAddress& p);

}
