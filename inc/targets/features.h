#pragma once

#include <vector>
#include <string>
#include <string_view>

#include "Json.h"

namespace OC {

    struct Features
    {
        std::vector<std::string> features;
    };

    namespace JSON {
        template<>
        std::string toJson(const Features& item);

        template<>
        Features fromJson(std::string_view json);
    }

}
