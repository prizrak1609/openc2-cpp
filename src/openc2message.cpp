#include "openc2message.h"

using namespace OC;

void OC::to_json(nlohmann::json &json, const OpenC2Message &item)
{
    json["action"] = item.action;
    json["target"] = item.target;
    json["args"] = item.args;
    json["command_id"] = item.commandId;
}

void OC::from_json(const nlohmann::json &result, OpenC2Message &message)
{
    message.action = result["action"].get<std::string>();
    message.target = result["target"].get<Target>();
    message.args = result["args"].get<Args>();
    message.commandId = result["command_id"].get<std::string>();
}
