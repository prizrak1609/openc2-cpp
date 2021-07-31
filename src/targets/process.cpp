#include "process.h"

void OC::to_json(nlohmann::json &json, const Process &item)
{
    json["pid"] = item.pid;
    json["name"] = item.name;
    json["cwd"] = item.cwd;
    json["executable"] = item.executable;
    json["parent"] = *item.parent;
    json["command_line"] = item.commandLine;
}

void OC::from_json(const nlohmann::json &result, Process &object)
{
    result["pid"].get_to(object.pid);
    result["name"].get_to(object.name);
    result["cwd"].get_to(object.cwd);
    result["executable"].get_to(object.executable);
    Process *parent = new Process();
    result["parent"].get_to(*(parent));
    object.parent = parent;
    result["command_line"].get_to(object.commandLine);
}
