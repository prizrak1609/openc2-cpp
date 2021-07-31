#include "jsonformatter.h"
#include "Json.h"

using namespace OC;
using namespace JSON;

OC::OpenC2Message OC::JsonFormatter::readOpenC2Message(const std::string &json)
{
    return fromJson<OpenC2Message>(json);
}

std::string OC::JsonFormatter::getJson(const OpenC2Message &message, bool prettyPrint)
{
    return toJson(message);
}

OC::OpenC2Response OC::JsonFormatter::readOpenC2Response(const std::string &json)
{
    return fromJson<OpenC2Response>(json);
}

std::string OC::JsonFormatter::getJson(OpenC2Response message, bool prettyPrint)
{
    return toJson(message);
}
