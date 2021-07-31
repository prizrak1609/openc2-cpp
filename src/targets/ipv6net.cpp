#include "ipv6net.h"

void OC::to_json(nlohmann::json &json, const Ipv6Net &item)
{
    json["ipv6_net"] = item.ipv6Net;
}

void OC::from_json(const nlohmann::json &result, Ipv6Net &object)
{
    result["ipv6_net"].get_to(object.ipv6Net);
}
