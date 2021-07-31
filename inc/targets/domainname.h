#pragma once

#include <string>
#include <nlohmann/json.hpp>

namespace OC {

    struct DomainName
    {
        std::string domainName;
    };

    void to_json(nlohmann::json& j, const DomainName& p);
    void from_json(const nlohmann::json& j, DomainName& p);

}
