#include "device.h"

using namespace OC;

template<>
OC::Device OC::JSON::fromJson<>(std::string_view json)
{
    nlohmann::json result = nlohmann::json::parse(json);

    Device device;
    device.deviceId = result["device_id"].get<std::string>();
    device.idnHostname = result["idn_hostname"].get<std::string>();
    device.hostname = result["hostname"].get<std::string>();

    return device;
}

template<>
std::string OC::JSON::toJson<>(const Device &item)
{
    nlohmann::json json;
    json["hostname"] = item.hostname;
    json["idn_hostname"] = item.idnHostname;
    json["device_id"] = item.deviceId;

    return json;
}
