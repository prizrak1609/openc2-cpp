#pragma once

#include <string>
#include <string_view>
#include <nlohmann/json.hpp>

namespace OC {

    struct Payload {
            std::string url;
            std::string bin;
    };

}
