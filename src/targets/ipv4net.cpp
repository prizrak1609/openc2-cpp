#include "ipv4net.h"

void OC::to_json(nlohmann::json &json, const Ipv4Net &item)
{
    json["ipv4_net"] = item.ipv4Net;
}

void OC::from_json(const nlohmann::json &result, Ipv4Net &object)
{
    result["ipv4_net"].get_to(object.ipv4Net);
}
