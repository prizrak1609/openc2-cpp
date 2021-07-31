#pragma once

#include <string>
#include <string_view>

#include "Target.h"
#include "Args.h"
#include "Json.h"

namespace OC {

    struct OpenC2Message {
            std::string action;
            Target target;
            Args args;
            std::string commandId;
    };

    namespace JSON {
        template<>
        std::string toJson(const OpenC2Message& item);

        template<>
        OpenC2Message fromJson(std::string_view json);
    }

}
