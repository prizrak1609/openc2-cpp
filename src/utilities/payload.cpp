#include "payload.h"

using namespace OC;

void OC::to_json(nlohmann::json &json, const Payload &item)
{
    if (!item.bin.empty()) {
        json["bin"] = item.bin;
    }
    if (!item.url.empty()) {
        json["url"] = item.url;
    }
}

void OC::from_json(const nlohmann::json &result, Payload &payload)
{
    if (result.contains("bin")) {
        payload.bin = result["bin"].get<std::string>();
    }
    if (result.contains("url")) {
        payload.url = result["url"].get<std::string>();
    }
}
