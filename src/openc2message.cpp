#include "openc2message.h"

using namespace OC;

void OC::to_json(nlohmann::json &json, const OpenC2Message &item)
{
    if (!item.action.empty()) {
        json["action"] = item.action;
    }
    if (item.target != nullptr) {
        json["target"] = *(item.target);
    }
    if (item.args != nullptr) {
        json["args"] = *(item.args);
    }
    if (!item.commandId.empty()) {
        json["command_id"] = item.commandId;
    }
}

void OC::from_json(const nlohmann::json &result, OpenC2Message &message)
{
    if (result.contains("action")) {
        message.action = result["action"].get<std::string>();
    }
    if (result.contains("target")) {
        Target *target = new Target();
        result["target"].get_to(*(target));
        message.target = target;
    }
    if (result.contains("args")) {
        Args *args = new Args();
        result["args"].get_to(*(args));
        message.args = args;
    }
    if (result.contains("command_id")) {
        message.commandId = result["command_id"].get<std::string>();
    }
}
