#include "target.h"

void OC::to_json(nlohmann::json &j, const Target &p)
{
#define target_field(field) \
    if(p.field != nullptr) { \
        j[#field] = *(p.field); \
    }

    target_field(artifact);
    target_field(device);
    target_field(domainName);
    target_field(emailAddress);
    target_field(features);
    target_field(file);
    target_field(idnDomainName);
    target_field(idnEmailAddress);
    target_field(ipv4Net);
    target_field(ipv4Connection);
    target_field(ipv6Net);
    target_field(ipv6Connection);
    target_field(iri);
    target_field(macAddress);
    target_field(process);
    target_field(properties);
    target_field(uri);

#undef target_field
}

void OC::from_json(const nlohmann::json &j, Target &p)
{
#define target_field(field, type) \
    { \
    if(j.contains(#field)) { \
        type *object = new type(); \
        j[#field].get_to(*(object)); \
        p.field = object; \
    } \
    }

    target_field(artifact, Artifact);
    target_field(device, Device);
    target_field(domainName, DomainName);
    target_field(emailAddress, EmailAddress);
    target_field(features, Features);
    target_field(file, File);
    target_field(idnDomainName, IdnDomainName);
    target_field(idnEmailAddress, IdnEmailAddress);
    target_field(ipv4Net, Ipv4Net);
    target_field(ipv4Connection, Ipv4Connection);
    target_field(ipv6Net, Ipv6Net);
    target_field(ipv6Connection, Ipv6Connection);
    target_field(iri, Iri);
    target_field(macAddress, MacAddress);
    target_field(process, Process);
    target_field(properties, Properties);
    target_field(uri, URI);

#undef target_field
}
