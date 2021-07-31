#pragma once

#include <string>

#include "Json.h"

namespace OC {

    struct DomainName
    {
        std::string domainName;
    };

    namespace JSON {
        template<>
        std::string toJson(const DomainName& item);

        template<>
        DomainName fromJson(std::string_view json);
    }

}
