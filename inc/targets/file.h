#pragma once

#include <string>
#include <string_view>
#include <unordered_map>

#include "Json.h"

namespace OC {

    struct File
    {
        std::string name;
        std::string path;
        std::unordered_map<std::string, std::string> hashes;
    };

    namespace JSON {
        template<>
        std::string toJson(const File& item);

        template<>
        File fromJson(std::string_view json);
    }

}
