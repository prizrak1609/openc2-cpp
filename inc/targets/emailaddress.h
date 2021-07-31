#pragma once

#include <string>

#include "Json.h"

namespace OC {

    struct EmailAddress
    {
       std::string emailAddress;
    };

    namespace JSON {
        template<>
        std::string toJson(const EmailAddress& item);

        template<>
        EmailAddress fromJson(std::string_view json);
    }

}
