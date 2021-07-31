#pragma once

#include <string>
#include <string_view>
#include <nlohmann/json.hpp>

namespace OC {

    struct IdnDomainName
    {
        std::string idnDomainName;
    };

    void to_json(nlohmann::json& j, const IdnDomainName& p);
    void from_json(const nlohmann::json& j, IdnDomainName& p);

}
