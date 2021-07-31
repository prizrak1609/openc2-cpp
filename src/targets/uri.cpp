#include "uri.h"

void OC::to_json(nlohmann::json &j, const URI &p)
{
    if (!p.uri.empty()) {
        j["uri"] = p.uri;
    }
}

void OC::from_json(const nlohmann::json &j, URI &p)
{
    if (j.contains("uri")) {
        j["uri"].get_to(p.uri);
    }
}
