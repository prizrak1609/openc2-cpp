#include "file.h"

using namespace OC;

void to_json(nlohmann::json &json, const File &item)
{
    json["name"] = item.name;
    json["path"] = item.path;
    json["hashes"] = item.hashes;
}

void from_json(const nlohmann::json &result, File &file)
{
    result["name"].get_to(file.name);
    result["path"].get_to(file.path);
    result["hashes"].get_to(file.hashes);
}
