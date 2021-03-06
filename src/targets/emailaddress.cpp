#include "emailaddress.h"

using namespace OC;

void OC::to_json(nlohmann::json &json, const EmailAddress &item)
{
    json["email_addr"] = item.emailAddress;
}

void OC::from_json(const nlohmann::json &result, EmailAddress &emailAddress)
{
    emailAddress.emailAddress = result["email_addr"].get<std::string>();
}
