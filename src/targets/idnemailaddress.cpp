#include "idnemailaddress.h"

template<>
std::string OC::JSON::toJson<>(const IdnEmailAddress &item)
{
    nlohmann::json json;
    json["idn_email_addr"] = item.idnEmailAddress;
    return json;
}

template<>
OC::IdnEmailAddress OC::JSON::fromJson<>(std::string_view json)
{
    nlohmann::json result = nlohmann::json::parse(json);

    IdnEmailAddress object;
    result["idn_email_addr"].get_to(object.idnEmailAddress);
    return object;
}
