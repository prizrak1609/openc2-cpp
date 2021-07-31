#include "features.h"

using namespace OC;

void to_json(nlohmann::json &json, const Features &item)
{
    json["features"] = item.features;
}

void from_json(const nlohmann::json &result, Features &features)
{
    features.features = result["features"].get<std::vector<std::string>>();
}
