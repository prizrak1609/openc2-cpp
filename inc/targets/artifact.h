#pragma once

#include <string>
#include <unordered_map>

#include "payload.h"
#include "Json.h"
#include "validation.h"

namespace OC {

    class Artifact : public Validation {
        public:
            Artifact() = default;
            ~Artifact() = default;

            std::string mimeType;
            Payload payload;
            std::unordered_map<std::string, std::string> hashes;

            Artifact& addHashes(std::string_view key, std::string_view hash, bool& error);
            bool validateHash(std::string_view key, std::string_view value);

            bool isValid();
    };

    namespace JSON {
        template<>
        std::string toJson(const Artifact& item);

        template<>
        Artifact fromJson(std::string_view json);
    }

}
