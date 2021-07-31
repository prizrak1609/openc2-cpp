#pragma once

#include <vector>
#include <string>
#include <string_view>
#include <nlohmann/json.hpp>

namespace OC {

    struct Features
    {
        std::vector<std::string> features;
    };

}
