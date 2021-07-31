#pragma once

#include <unordered_map>
#include <any>
#include <string>
#include <string_view>
#include <json_dto/pub.hpp>

namespace OC {

    class OpenC2Response {

            template<typename Json_Io>
            friend void json_io(Json_Io &io, OC::OpenC2Response &response);

        public:
            OpenC2Response(unsigned int status);
            ~OpenC2Response() = default;

            OpenC2Response& addResults(std::string key, std::any value);

        private:
            unsigned int status;
            std::string statusText;
            std::unordered_map<std::string, std::any> results;
    };

}

namespace json_dto {

    template<typename Json_Io>
    void json_io(Json_Io &io, OC::OpenC2Response &response) {
        io & json_dto::mandatory("status", response.status)
                & json_dto::optional("statusText", response.statusText, {})
                & json_dto::optional("results", response.results, {});
    }

}
