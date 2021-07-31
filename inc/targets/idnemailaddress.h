#pragma once

#include <string>
#include <string_view>

#include "Json.h"

namespace OC {

    struct IdnEmailAddress
    {
        std::string idnEmailAddress;
    };

    namespace JSON {
        template<>
        std::string toJson(const IdnEmailAddress& item);

        template<>
        IdnEmailAddress fromJson(std::string_view json);
    }

}
