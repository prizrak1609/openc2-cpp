#pragma once

#include "artifact.h"
#include "device.h"
#include "domainname.h"
#include "emailaddress.h"
#include "features.h"
#include "file.h"
#include "idndomainname.h"
#include "idnemailaddress.h"
#include "ipv4net.h"
#include "ipv4connection.h"
#include "ipv6net.h"
#include "ipv6connection.h"
#include "iri.h"
#include "macaddress.h"
#include "process.h"
#include "properties.h"
#include "uri.h"

namespace OC {

    struct Target
    {
        Artifact *artifact = nullptr;
        Device *device = nullptr;
        DomainName *domainName = nullptr;
        EmailAddress *emailAddress = nullptr;
        Features *features = nullptr;
        File *file = nullptr;
        IdnDomainName *idnDomainName = nullptr;
        IdnEmailAddress *idnEmailAddress = nullptr;
        Ipv4Net *ipv4Net = nullptr;
        Ipv4Connection *ipv4Connection = nullptr;
        Ipv6Net *ipv6Net = nullptr;
        Ipv6Connection *ipv6Connection = nullptr;
        Iri *iri = nullptr;
        MacAddress *macAddress = nullptr;
        Process *process = nullptr;
        Properties *properties = nullptr;
        URI *uri = nullptr;
    };

    void to_json(nlohmann::json& j, const Target& p);
    void from_json(const nlohmann::json& j, Target& p);

}
