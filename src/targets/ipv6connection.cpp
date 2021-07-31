#include "ipv6connection.h"

void OC::to_json(nlohmann::json &json, const Ipv6Connection &item)
{
    json["src_addr"] = item.srcAddr;
    json["src_port"] = item.srcPort;
    json["dst_addr"] = item.dstAddr;
    json["dst_port"] = item.dstPort;
    json["protocol"] = item.protocol;
}

void OC::from_json(const nlohmann::json &result, Ipv6Connection &object)
{
    result["src_addr"].get_to(object.srcAddr);
    result["src_port"].get_to(object.srcPort);
    result["dst_addr"].get_to(object.dstAddr);
    result["dst_port"].get_to(object.dstPort);
    result["protocol"].get_to(object.protocol);
}
