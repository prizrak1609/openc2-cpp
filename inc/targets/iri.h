#pragma once

#include <string>
#include <string_view>

#include "Json.h"

namespace OC {

    struct Iri
    {
        std::string iri;
    };

    namespace JSON {
        template<>
        std::string toJson(const Iri& item);

        template<>
        Iri fromJson(std::string_view json);
    }

}
