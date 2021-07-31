#include "idnemailaddress.h"

void OC::to_json(nlohmann::json &json, const IdnEmailAddress &item)
{
    json["idn_email_addr"] = item.idnEmailAddress;
}

void OC::from_json(const nlohmann::json &result, IdnEmailAddress &object)
{
    result["idn_email_addr"].get_to(object.idnEmailAddress);
}
