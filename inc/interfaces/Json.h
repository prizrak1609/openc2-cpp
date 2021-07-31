#pragma once

#include <string>
#include <string_view>
#include <nlohmann/json.hpp>

namespace OC {

    namespace JSON {
        template<typename T>
        std::string toJson(const T& item);

        template<typename T>
        T fromJson(std::string_view json);
    }

}
