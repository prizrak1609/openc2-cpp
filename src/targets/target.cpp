#include "target.h"

void OC::to_json(nlohmann::json &j, const Target &p)
{
    if(p.artifact != nullptr) {
        j["artifact"] = *(p.artifact);
    }
    if(p.device != nullptr) {
        j["device"] = *(p.device);
    }
    if(p.domainName != nullptr) {
        j["domain_name"] = p.domainName->domainName;
    }
    if(p.emailAddress != nullptr) {
        j["email_addr"] = p.emailAddress->emailAddress;
    }
    if(p.features != nullptr) {
        j["features"] = p.features->features;
    }
    if(p.file != nullptr) {
        j["file"] = *(p.file);
    }
    if(p.idnDomainName != nullptr) {
        j["idn_domain_name"] = p.idnDomainName->idnDomainName;
    }
    if(p.idnEmailAddress != nullptr) {
        j["idn_email_addr"] = p.idnEmailAddress->idnEmailAddress;
    }
    if(p.ipv4Net != nullptr) {
        j["ipv4_net"] = p.ipv4Net->ipv4Net;
    }
    if(p.ipv4Connection != nullptr) {
        j["ipv4_connection"] = *(p.ipv4Connection);
    }
    if(p.ipv6Net != nullptr) {
        j["ipv6_net"] = p.ipv6Net->ipv6Net;
    }
    if(p.ipv6Connection != nullptr) {
        j["ipv6_connection"] = *(p.ipv6Connection);
    }
    if(p.iri != nullptr) {
        j["iri"] = p.iri->iri;
    }
    if(p.macAddress != nullptr) {
        j["mac_addr"] = p.macAddress->macAddress;
    }
    if(p.process != nullptr) {
        j["process"] = *(p.process);
    }
    if(p.properties != nullptr) {
        j["properties"] = p.properties->properties;
    }
    if(p.uri != nullptr) {
        j["uri"] = p.uri->uri;
    }
}

void OC::from_json(const nlohmann::json &j, Target &p)
{
        if(j.contains("artifact")) {
            Artifact *object = new Artifact();
            j["artifact"].get_to(*(object));
            p.artifact = object;
        }

        if(j.contains("device")) {
            Device *object = new Device();
            j["device"].get_to(*(object));
            p.device = object;
        }

        if(j.contains("domain_name")) {
            DomainName *object = new DomainName();
            j["domain_name"].get_to(object->domainName);
            p.domainName = object;
        }
        if(j.contains("email_addr")) {
            EmailAddress *object = new EmailAddress();
            j["email_addr"].get_to(object->emailAddress);
            p.emailAddress = object;
        }
        if(j.contains("features")) {
            Features *object = new Features();
            j["features"].get_to(object->features);
            p.features = object;
        }
        if(j.contains("file")) {
            File *object = new File();
            j["file"].get_to(*(object));
            p.file = object;
        }
        if(j.contains("idn_domain_name")) {
            IdnDomainName *object = new IdnDomainName();
            j["idn_domain_name"].get_to(object->idnDomainName);
            p.idnDomainName = object;
        }
        if(j.contains("idn_email_addr")) {
            IdnEmailAddress *object = new IdnEmailAddress();
            j["idn_email_addr"].get_to(object->idnEmailAddress);
            p.idnEmailAddress = object;
        }
        if(j.contains("ipv4_net")) {
            Ipv4Net *object = new Ipv4Net();
            j["ipv4_net"].get_to(object->ipv4Net);
            p.ipv4Net = object;
        };
        if(j.contains("ipv4_connection")) {
            Ipv4Connection *object = new Ipv4Connection();
            j["ipv4_connection"].get_to(*(object));
            p.ipv4Connection = object;
        };
        if(j.contains("ipv6_net")) {
            Ipv6Net *object = new Ipv6Net();
            j["ipv6_net"].get_to(object->ipv6Net);
            p.ipv6Net = object;
        };
        if(j.contains("ipv6_connection")) {
            Ipv6Connection *object = new Ipv6Connection();
            j["ipv6_connection"].get_to(*(object));
            p.ipv6Connection = object;
        };
        if(j.contains("iri")) {
            Iri *object = new Iri();
            j["iri"].get_to(object->iri);
            p.iri = object;
        };
        if(j.contains("mac_addr")) {
            MacAddress *object = new MacAddress();
            j["mac_addr"].get_to(object->macAddress);
            p.macAddress = object;
        };
        if(j.contains("process")) {
            Process *object = new Process();
            j["process"].get_to(*(object));
            p.process = object;
        };
        if(j.contains("properties")) {
            Properties *object = new Properties();
            j["properties"].get_to(object->properties);
            p.properties = object;
        };
        if(j.contains("uri")) {
            URI *object = new URI();
            j["uri"].get_to(object->uri);
            p.uri = object;
        };
}
