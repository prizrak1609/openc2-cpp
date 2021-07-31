#include "iri.h"

template<>
std::string OC::JSON::toJson<>(const Iri &item)
{
    nlohmann::json json;
    json["iri"] = item.iri;
    return json;
}

template<>
OC::Iri OC::JSON::fromJson<>(std::string_view json)
{
    nlohmann::json result = nlohmann::json::parse(json);

    Iri object;
    result["iri"].get_to(object.iri);
    return object;
}
