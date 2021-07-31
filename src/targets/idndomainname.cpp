#include "idndomainname.h"

template<>
std::string OC::JSON::toJson<>(const IdnDomainName &item)
{
    nlohmann::json json;
    json["idn_domain_name"] = item.idnDomainName;
    return json;
}

template<>
OC::IdnDomainName OC::JSON::fromJson<>(std::string_view json)
{
    nlohmann::json result = nlohmann::json::parse(json);

    IdnDomainName object;
    result["idn_domain_name"].get_to(object.idnDomainName);
    return object;
}
