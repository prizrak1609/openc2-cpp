#include "process.h"

void OC::to_json(nlohmann::json &json, const Process &item)
{
    json["pid"] = item.pid;
    if (!item.name.empty()) {
        json["name"] = item.name;
    }
    if (!item.cwd.empty()) {
        json["cwd"] = item.cwd;
    }
    if (item.executable != nullptr) {
        json["executable"] = *item.executable;
    }
    if (item.parent != nullptr) {
        json["parent"] = *item.parent;
    };
    if (!item.commandLine.empty()) {
        json["command_line"] = item.commandLine;
    }
}

void OC::from_json(const nlohmann::json &result, Process &object)
{
    if (result.contains("pid")) {
        result["pid"].get_to(object.pid);
    }
    if (result.contains("name")) {
        result["name"].get_to(object.name);
    }
    if (result.contains("cwd")) {
        result["cwd"].get_to(object.cwd);
    }
    if (result.contains("executable")) {
        File *file = new File();
        result["executable"].get_to(*file);
        object.executable = file;
    }
    if (result.contains("parent")) {
        Process *parent = new Process();
        result["parent"].get_to(*parent);
        object.parent = parent;
    }
    if (result.contains("command_line")) {
        result["command_line"].get_to(object.commandLine);
    }
}
