#pragma once

#include <string>

#include "Json.h"

namespace OC {

    struct Payload {
            std::string url;
            std::string bin;
    };

    namespace JSON {
        template<>
        std::string toJson(const Payload& item);

        template<>
        Payload fromJson(std::string json);
    }

}
