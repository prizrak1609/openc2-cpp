#include "domainname.h"

using namespace OC;

template<>
std::string OC::JSON::toJson<>(const DomainName &item)
{
    nlohmann::json json;
    json["domain_name"] = item.domainName;

    return json;
}

template<>
OC::DomainName OC::JSON::fromJson<>(std::string_view json)
{
    nlohmann::json result = nlohmann::json::parse(json);

    DomainName domainName;
    domainName.domainName = result["domain_name"].get<std::string>();
    return domainName;
}
