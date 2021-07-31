#pragma once

#include <string>
#include <string_view>

#include "openc2message.h"
#include "openc2response.h"

namespace OC {

    class JsonFormatter {
        public:
            JsonFormatter() = default;
            ~JsonFormatter() = default;

            /**
              * Read a OpenC2 JSON string and convert it into a OpenC2Message object
              *
              * @param json OpenC2Message JSON string
              * @return OpenC2Message OpenC2Message object represented by the JSON string
              */
            static OpenC2Message readOpenC2Message(const std::string &json);
            /**
              * Convert an OpenC2Message object to a JSON string
              *
              * @param message OpenC2Message object to be serialized into a JSON string
              * @param prettyPrint boolean to toggle if the return string is in human readable or not
              * @return String containing the JSON representation of the OpenC2Message object
              */
            static std::string getJson(const OpenC2Message& message, bool prettyPrint);
            /**
              * Read a OpenC2 JSON string and convert it into a OpenC2Response object
              *
              * @param json response JSON string
              * @return OpenC2Response object
              */
            static OpenC2Response readOpenC2Response(const std::string &json);
            /**
              * Convert an OpenC2Response object to a JSON string
              *
              * @param message OpenC2Message object to be converted to JSON
              * @param prettyPrint boolean to toggle if the return string is in human readable or not
              * @return String containing the JSON representation of the object
              */
            static std::string getJson(const OpenC2Response& message, bool prettyPrint);

            static std::string removePrettyFormatting(std::string_view text);
    };

}
