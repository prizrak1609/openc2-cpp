#include "macaddress.h"

template<>
std::string OC::JSON::toJson<>(const MacAddress &item)
{
    nlohmann::json json;
    json["mac_addr"] = item.macAddress;
    return json;
}

template<>
OC::MacAddress OC::JSON::fromJson<>(std::string_view json)
{
    nlohmann::json result = nlohmann::json::parse(json);

    MacAddress object;
    result["mac_addr"].get_to(object.macAddress);
    return object;
}
