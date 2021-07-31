#pragma once

#include <string>
#include <json_dto/pub.hpp>

namespace OC {

    struct Payload {
            std::string url;
            std::string bin;
    };

}

namespace json_dto {

    template<typename Json_Io>
    void json_io(Json_Io &io, OC::Payload &payload) {
        io & json_dto::mandatory("url", payload.url)
                & json_dto::optional("bin", payload.bin, {});
    }

}
