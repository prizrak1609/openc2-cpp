#include "payload.h"

using namespace OC;

template<>
std::string OC::JSON::toJson<>(const Payload& item)
{
    nlohmann::json json;
    json["bin"] = item.bin;
    json["url"] = item.url;
    return json;
}

template<>
OC::Payload OC::JSON::fromJson<>(std::string_view json)
{
    nlohmann::json result = nlohmann::json::parse(json);

    Payload payload;
    payload.bin = result["bin"].get<std::string>();
    payload.url = result["url"].get<std::string>();
    return payload;
}
