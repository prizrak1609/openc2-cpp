#pragma once

#include <unordered_map>
#include <any>
#include <string>
#include <string_view>
#include <nlohmann/json.hpp>

namespace OC {

    struct OpenC2Response {
            unsigned int status = 0;
            std::string statusText;
            std::unordered_map<std::string, nlohmann::json> results;

            OpenC2Response& addResults(const std::string &key, const nlohmann::json &value);
    };

    void to_json(nlohmann::json& j, const OpenC2Response& p);
    void from_json(const nlohmann::json& j, OpenC2Response& p);

}
