#include "jsonformatter.h"

#include <json_dto/pub.hpp>

using namespace OC;

OC::OpenC2Message OC::JsonFormatter::readOpenC2Message(const std::string &json, bool& error)
{
    error = false;
    try {
        return json_dto::from_json<OpenC2Message>(json);
    } catch(const std::exception &ex) {
        error = true;
        return {};
    }
}

std::string OC::JsonFormatter::getJson(const OpenC2Message &message, bool prettyPrint, bool& error)
{
    error = false;
    try {
        std::string json;
        if (prettyPrint) {
            json = json_dto::to_json(message, json_dto::pretty_writer_params_t{}
                                     .indent_char(' ')
                                     .indent_char_count(3u)
                                     .format_options(rapidjson::kFormatSingleLineArray));
        } else {
            json = json_dto::to_json(message);
        }
        return json;
    } catch(const std::exception &ex) {
        error = true;
        return {};
    }
}

OC::OpenC2Response OC::JsonFormatter::readOpenC2Response(const std::string &json, bool& error)
{
    error = false;
    try {
        return json_dto::from_json<OpenC2Response>(json);
    } catch(const std::exception &ex) {
        error = true;
        return {};
    }
}

std::string OC::JsonFormatter::getJson(OpenC2Response message, bool prettyPrint, bool& error)
{
    error = false;
    try {
        std::string json;
        if (prettyPrint) {
            json = json_dto::to_json(message, json_dto::pretty_writer_params_t{}
                                     .indent_char(' ')
                                     .indent_char_count(3u)
                                     .format_options(rapidjson::kFormatSingleLineArray));
        } else {
            json = json_dto::to_json(message);
        }
        return json;
    } catch(const std::exception &ex) {
        error = true;
        return {};
    }
}
