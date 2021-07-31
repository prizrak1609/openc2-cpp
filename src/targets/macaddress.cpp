#include "macaddress.h"

void OC::to_json(nlohmann::json &json, const MacAddress &item)
{
    json["mac_addr"] = item.macAddress;
}

void OC::from_json(const nlohmann::json &result, MacAddress &object)
{
    result["mac_addr"].get_to(object.macAddress);
}
