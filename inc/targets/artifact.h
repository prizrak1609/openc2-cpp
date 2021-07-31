#pragma once

#include <string>
#include <unordered_map>
#include <nlohmann/json.hpp>

#include "payload.h"

namespace OC {

    struct Artifact {
            std::string mimeType;
            Payload payload;
            std::unordered_map<std::string, std::string> hashes;

            Artifact& addHashes(std::string_view key, std::string_view hash, bool& error);
            bool validateHash(std::string_view key, std::string_view value);
    };

    void to_json(nlohmann::json& j, const Artifact& p);
    void from_json(const nlohmann::json& j, Artifact& p);

}
