#pragma once

#include <string>
#include <nlohmann/json.hpp>

namespace OC {

    struct EmailAddress
    {
       std::string emailAddress;
    };

    void to_json(nlohmann::json& j, const EmailAddress& p);
    void from_json(const nlohmann::json& j, EmailAddress& p);

}
