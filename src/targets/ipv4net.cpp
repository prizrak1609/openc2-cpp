#include "ipv4net.h"

template<>
std::string OC::JSON::toJson<>(const Ipv4Net &item)
{
    nlohmann::json json;
    json["ipv4_net"] = item.ipv4Net;
    return json;
}

template<>
OC::Ipv4Net OC::JSON::fromJson<>(std::string_view json)
{
    nlohmann::json result = nlohmann::json::parse(json);

    Ipv4Net object;
    result["ipv4_net"].get_to(object.ipv4Net);
    return object;
}
