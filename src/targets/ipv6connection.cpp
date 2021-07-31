#include "ipv6connection.h"

template<>
std::string OC::JSON::toJson<>(const Ipv6Connection &item)
{
    nlohmann::json json;
    json["src_addr"] = item.srcAddr;
    json["src_port"] = item.srcPort;
    json["dst_addr"] = item.dstAddr;
    json["dst_port"] = item.dstPort;
    json["protocol"] = item.protocol;
    return json;
}

template<>
OC::Ipv6Connection OC::JSON::fromJson<>(std::string_view json)
{
    nlohmann::json result = nlohmann::json::parse(json);

    Ipv6Connection object;
    result["src_addr"].get_to(object.srcAddr);
    result["src_port"].get_to(object.srcPort);
    result["dst_addr"].get_to(object.dstAddr);
    result["dst_port"].get_to(object.dstPort);
    result["protocol"].get_to(object.protocol);
    return object;
}
