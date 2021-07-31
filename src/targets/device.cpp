#include "device.h"

using namespace OC;

void OC::to_json(nlohmann::json &json, const Device &item)
{
    json["hostname"] = item.hostname;
    json["idn_hostname"] = item.idnHostname;
    json["device_id"] = item.deviceId;
}

void OC::from_json(const nlohmann::json &result, Device &device)
{
    device.deviceId = result["device_id"].get<std::string>();
    device.idnHostname = result["idn_hostname"].get<std::string>();
    device.hostname = result["hostname"].get<std::string>();
}
