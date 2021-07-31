#include "domainname.h"

using namespace OC;

void OC::to_json(nlohmann::json &json, const DomainName &item)
{
    json["domain_name"] = item.domainName;
}

void OC::from_json(const nlohmann::json &result, DomainName &domainName)
{
    domainName.domainName = result["domain_name"].get<std::string>();
}
