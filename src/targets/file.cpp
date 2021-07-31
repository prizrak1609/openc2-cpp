#include "file.h"

using namespace OC;

template<>
std::string OC::JSON::toJson<>(const File &item)
{
    nlohmann::json json;
    json["name"] = item.name;
    json["path"] = item.path;
    json["hashes"] = item.hashes;
    return json;
}

template<>
OC::File OC::JSON::fromJson<>(std::string_view json)
{
    nlohmann::json result = nlohmann::json::parse(json);

    File file;
    result["name"].get_to(file.name);
    result["path"].get_to(file.path);
    result["hashes"].get_to(file.hashes);
    return file;
}
