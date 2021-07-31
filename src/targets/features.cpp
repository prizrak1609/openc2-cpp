#include "features.h"

using namespace OC;

template<>
std::string OC::JSON::toJson<>(const Features &item)
{
    nlohmann::json json;
    json["features"] = item.features;
    return json;
}

template<>
OC::Features OC::JSON::fromJson<>(std::string_view json)
{
    nlohmann::json result = nlohmann::json::parse(json);

    Features features;
    features.features = result["features"].get<std::vector<std::string>>();
    return features;
}
