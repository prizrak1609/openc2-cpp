#include "properties.h"

void OC::to_json(nlohmann::json &j, const Properties &p)
{
    j["properties"] = p.properties;
}

void OC::from_json(const nlohmann::json &j, Properties &p)
{
    j["properties"].get_to(p.properties);
}
