#pragma once

#include <string>
#include <string_view>

#include "Json.h"

namespace OC {

    struct IdnDomainName
    {
        std::string idnDomainName;
    };

    namespace JSON {
        template<>
        std::string toJson(const IdnDomainName& item);

        template<>
        IdnDomainName fromJson(std::string_view json);
    }

}
