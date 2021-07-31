#pragma once

#include <string>
#include <string_view>
#include <unordered_map>
#include <nlohmann/json.hpp>

namespace OC {

    struct File
    {
        std::string name;
        std::string path;
        std::unordered_map<std::string, std::string> hashes;
    };

    void to_json(nlohmann::json& j, const File& p);
    void from_json(const nlohmann::json& j, File& p);

}
