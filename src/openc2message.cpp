#include "openc2message.h"

using namespace OC;

template<>
std::string OC::JSON::toJson<>(const OpenC2Message& item)
{
    nlohmann::json json;
    json["action"] = item.action;
    json["target"] = toJson(item.target);
    json["args"] = toJson(item.args);
    json["command_id"] = item.commandId;
    return json;
}

template<>
OC::OpenC2Message OC::JSON::fromJson<>(std::string_view json)
{
    nlohmann::json result = nlohmann::json::parse(json);

    OpenC2Message message;
    message.action = result["action"].get<std::string>();
    message.target = fromJson<Target>(result["target"].get<std::string>());
    message.args = fromJson<Args>(result["args"].get<std::string>());
    message.commandId = result["command_id"].get<std::string>();
}
