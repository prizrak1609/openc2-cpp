#pragma once

#include <string>
#include <string_view>
#include <json_dto/pub.hpp>

#include "Target.h"
#include "Args.h"

namespace OC {

    struct OpenC2Message {
            std::string action;
            Target target;
            Args args;
            std::string commandId;
    };

}

namespace json_dto {

    template<typename Json_Io>
    void json_io(Json_Io &io, OC::OpenC2Message &response) {
        io & json_dto::mandatory("action", response.action)
                & json_dto::mandatory("target", response.target)
                & json_dto::optional("args", response.args, {})
                & json_dto::optional("command_id", response.commandId, {});
    }

}
