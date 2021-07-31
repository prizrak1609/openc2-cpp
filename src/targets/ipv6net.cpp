#include "ipv6net.h"

template<>
std::string OC::JSON::toJson<>(const Ipv6Net &item)
{
    nlohmann::json json;
    json["ipv6_net"] = item.ipv6Net;
    return json;
}

template<>
OC::Ipv6Net OC::JSON::fromJson<>(std::string_view json)
{
    nlohmann::json result = nlohmann::json::parse(json);

    Ipv6Net object;
    result["ipv6_net"].get_to(object.ipv6Net);
    return object;
}
