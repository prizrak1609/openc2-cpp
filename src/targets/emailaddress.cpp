#include "emailaddress.h"

using namespace OC;

template<>
std::string OC::JSON::toJson<>(const EmailAddress &item)
{
    nlohmann::json json;
    json["email_addr"] = item.emailAddress;
    return json;
}

template<>
OC::EmailAddress OC::JSON::fromJson<>(std::string_view json)
{
    nlohmann::json result = nlohmann::json::parse(json);

    EmailAddress emailAddress;
    emailAddress.emailAddress = result["email_addr"].get<std::string>();
    return emailAddress;
}
