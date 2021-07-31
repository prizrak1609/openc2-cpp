#include "idndomainname.h"

void OC::to_json(nlohmann::json &json, const IdnDomainName &item)
{
    json["idn_domain_name"] = item.idnDomainName;
}

void OC::from_json(const nlohmann::json &result, IdnDomainName &object)
{
    result["idn_domain_name"].get_to(object.idnDomainName);
}
