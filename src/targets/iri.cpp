#include "iri.h"

void OC::to_json(nlohmann::json &json, const Iri &item)
{
    json["iri"] = item.iri;
}

void OC::from_json(const nlohmann::json &result, Iri &object)
{
    result["iri"].get_to(object.iri);
}
