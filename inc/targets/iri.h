#pragma once

#include <string>
#include <string_view>
#include <nlohmann/json.hpp>

namespace OC {

    struct Iri
    {
        std::string iri;
    };

    void to_json(nlohmann::json& j, const Iri& p);
    void from_json(const nlohmann::json& j, Iri& p);

}
