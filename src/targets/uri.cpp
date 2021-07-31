#include "uri.h"

void OC::to_json(nlohmann::json &j, const URI &p)
{
    j["uri"] = p.uri;
}

void OC::from_json(const nlohmann::json &j, URI &p)
{
    j["uri"].get_to(p.uri);
}
