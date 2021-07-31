#include "features.h"

using namespace OC;

void OC::to_json(nlohmann::json &json, const Features &item)
{
    json["features"] = item.features;
}

void OC::from_json(const nlohmann::json &result, Features &features)
{
    features.features = result["features"].get<std::vector<std::string>>();
}
