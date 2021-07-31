#pragma once

#include <unordered_map>
#include <any>
#include <string>
#include <string_view>

#include "Json.h"

namespace OC {

    struct OpenC2Response {
            unsigned int status = 0;
            std::string statusText;
            std::unordered_map<std::string, std::any> results;

            OpenC2Response& addResults(const std::string &key, std::any value);
    };

    namespace JSON {
        template<>
        std::string toJson(const OpenC2Response& item);

        template<>
        OpenC2Response fromJson(std::string_view json);
    }

}
