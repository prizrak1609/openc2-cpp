#include "payload.h"

using namespace OC;

void OC::to_json(nlohmann::json &json, const Payload &item)
{
    json["bin"] = item.bin;
    json["url"] = item.url;
}

void OC::from_json(const nlohmann::json &result, Payload &payload)
{
    payload.bin = result["bin"].get<std::string>();
    payload.url = result["url"].get<std::string>();
}
