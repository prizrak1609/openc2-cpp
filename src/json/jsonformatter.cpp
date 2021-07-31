#include "jsonformatter.h"
#include <nlohmann/json.hpp>

using namespace OC;

OC::OpenC2Message OC::JsonFormatter::readOpenC2Message(const std::string &json)
{
    OpenC2Message message;
    nlohmann::json jsonObj = nlohmann::json::parse(json);
    jsonObj.get_to(message);

    return message;
}

std::string OC::JsonFormatter::getJson(const OpenC2Message &message, bool prettyPrint)
{
    nlohmann::json obj = message;
    if (prettyPrint) {
        return obj.dump(4);
    } else {
        return obj.dump();
    }
}

OC::OpenC2Response OC::JsonFormatter::readOpenC2Response(const std::string &json)
{
    OpenC2Response message;
    nlohmann::json jsonObj = nlohmann::json::parse(json);
    jsonObj.get_to(message);

    return message;
}

std::string OC::JsonFormatter::getJson(const OpenC2Response &message, bool prettyPrint)
{
    nlohmann::json obj = message;
    if (prettyPrint) {
        return obj.dump(4);
    } else {
        return obj.dump();
    }
}
