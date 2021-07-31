#include <gtest/gtest.h>
#include <string>
#include <iostream>

#include "openc2message.h"
#include "args.h"
#include "jsonformatter.h"
#include "artifact.h"
#include "device.h"
#include "domainname.h"
#include "emailaddress.h"
#include "features.h"
#include "file.h"
#include "idndomainname.h"
#include "idnemailaddress.h"
#include "ipv4connection.h"
#include "ipv4net.h"
#include "ipv6connection.h"
#include "ipv6net.h"
#include "iri.h"
#include "macaddress.h"
#include "process.h"
#include "properties.h"
#include "target.h"
#include "uri.h"
#include "actiontype.h"
#include "featuretype.h"
#include "hashtype.h"
#include "l4protocoltype.h"
#include "payload.h"

using namespace OC;

class TestMessage : public ::testing::Test {
    protected:
        std::string expected = R"===({
 "action":"create",
 "target":{
  "artifact":{
   "payload":{
    "url":"www.testurl.com"
   },
   "hashes":{
    "sha1":"1234567890ABCDEF1234567890ABCDEF12345678",
    "sha256":"1234567890ABCDEF1234567890ABCDEF1234567890ABCDEF1234567890ABDEF1",
    "md5":"1234567890ABCDEF1234567890ABCDEF"
   },
   "mime_type":"My MIME Type"
  },
  "device":{
   "hostname":"device hostname",
   "idn_hostname":"device idn hostname",
   "device_id":"Device id"
  },
  "features":[
   "versions","profiles","pairs","rate_limit"
  ],
  "file":{
   "name":"File name",
   "path":"File path",
   "hashes":{
    "sha1":"1234567890ABCDEF1234567890ABCDEF12345678",
    "sha256":"1234567890ABCDEF1234567890ABCDEF1234567890ABCDEF1234567890ABDEF1",
    "md5":"1234567890ABCDEF1234567890ABCDEF"
   }
  },
  "iri":"My IRI identifier",
  "process":{
   "pid":12354,
   "name":"Process name",
   "cwd":"Process CWD",
   "executable":{
    "name":"File name",
    "path":"File path",
    "hashes":{
     "sha1":"1234567890ABCDEF1234567890ABCDEF12345678",
     "sha256":"1234567890ABCDEF1234567890ABCDEF1234567890ABCDEF1234567890ABDEF1",
     "md5":"1234567890ABCDEF1234567890ABCDEF"
    }
   },
   "parent":{
    "pid":43521,
    "name":"Process parent name",
    "cwd":"Process parent CWD"
   },
   "command_line":"Process command line statement"
   },
   "properties":[
    "Tag1","Tag2","Tag3","Tag4"
   ],
   "uri":"www.myuri.com",
   "domain_name":"Domain name",
   "email_addr":"Email address",
   "idn_domain_name":"IDN Domain name",
   "idn_email_addr":"IDN Email address",
   "ipv4_net":"10.0.0.0/24",
   "ipv4_connection":{
    "protocol":"tcp",
    "src_addr":"10.0.0.0/24",
    "src_port":8443,
    "dst_addr":"10.0.0.0/24",
    "dst_port":9443
   },
   "ipv6_net":"AE:00:E4:F1:04:65/24",
   "ipv6_connection":{
    "protocol":"tcp",
    "src_addr":"AE:00:E4:F1:04:65/24",
    "src_port":8443,
    "dst_addr":"AE:00:E4:F1:04:65/24",
    "dst_port":9443
   },
   "mac_addr":"This is my mac address"
  },
  "args":{
   "duration":30000,
   "start_time":1568209029693,
   "stop_time":1568209059693,
   "response_requested":"complete"
  },
  "command_id":"My command id is here"
 }
)===";

        std::string inputJson = R"===({
 "action":"create",
 "target":{
  "artifact":{
   "payload":{
    "url":"www.testurl.com"
   },
   "hashes":{
    "sha1":"1234567890ABCDEF1234567890ABCDEF12345678",
    "sha256":"1234567890ABCDEF1234567890ABCDEF1234567890ABCDEF1234567890ABDEF1",
    "md5":"1234567890ABCDEF1234567890ABCDEF"
   },
   "mime_type":"My MIME Type"
  },"device":{
   "hostname":"device hostname",
   "idn_hostname":"device idn hostname",
   "device_id":"Device id"
  },
  "features":[
   "versions","profiles","pairs","rate_limit"
  ],
  "file":{
   "name":"File name",
   "path":"File path",
   "hashes":{
    "sha1":"1234567890ABCDEF1234567890ABCDEF12345678",
    "sha256":"1234567890ABCDEF1234567890ABCDEF1234567890ABCDEF1234567890ABDEF1",
    "md5":"1234567890ABCDEF1234567890ABCDEF"
   }
  },
  "iri":"My IRI identifier",
  "process":{
   "pid":12354,
   "name":"Process name",
   "cwd":"Process CWD",
   "executable":{
    "name":"File name",
    "path":"File path",
    "hashes":{
     "sha1":"1234567890ABCDEF1234567890ABCDEF12345678",
     "sha256":"1234567890ABCDEF1234567890ABCDEF1234567890ABCDEF1234567890ABDEF1",
     "md5":"1234567890ABCDEF1234567890ABCDEF"
    }
   },
   "parent":{
    "pid":43521,
    "name":"Process parent name",
    "cwd":"Process parent CWD"
   },
   "command_line":"Process command line statement"
  },
  "properties":[
   "Tag1","Tag2","Tag3","Tag4"
  ],
  "uri":"www.myuri.com",
  "domain_name":"Domain name",
  "email_addr":"Email address",
  "idn_domain_name":"IDN Domain name",
  "idn_email_addr":"IDN Email address",
  "ipv4_net":"10.0.0.0/24",
  "ipv4_connection":{
   "protocol":"tcp",
   "src_addr":"10.0.0.0/24",
   "src_port":8443,
   "dst_addr":"10.0.0.0/24",
   "dst_port":9443
  },
  "ipv6_net":"AE:00:E4:F1:04:65/24",
  "ipv6_connection":{
   "protocol":"tcp",
   "src_addr":"AE:00:E4:F1:04:65/24",
   "src_port":8443,
   "dst_addr":"AE:00:E4:F1:04:65/24",
   "dst_port":9443
  },
  "mac_addr":"This is my mac address"
 },"args":{
  "duration":30000,
  "start_time":1568209029693,
  "stop_time":1568209059693,
  "response_requested":"complete"
 },
 "command_id":"My command id is here"
}
)===";
};

Artifact* getArtifact() {
    Artifact *artifact = new Artifact();

    artifact->mimeType = "My MIME Type";
    artifact->payload = Payload();
    artifact->payload.url = "www.testurl.com";
    bool error;
    artifact->addHashes(HashType::MD5, "1234567890ABCDEF1234567890ABCDEF", error)
            .addHashes(HashType::SHA1, "1234567890ABCDEF1234567890ABCDEF12345678", error)
            .addHashes(HashType::SHA256, "1234567890ABCDEF1234567890ABCDEF1234567890ABCDEF1234567890ABDEF1", error);

    return artifact;
}

Device* getDevice() {
    Device *device = new Device();

    device->deviceId = "Device id";
    device->hostname = "device hostname";
    device->idnHostname = "device idn hostname";

    return device;
}

DomainName* getDomainName() {
    DomainName *domainName = new DomainName();

    domainName->domainName = "Domain name";

    return domainName;
}

EmailAddress* getEmailAddress() {
    EmailAddress *emailAddr = new EmailAddress();

    emailAddr->emailAddress = "Email address";

    return emailAddr;
}

Features* getFeatures() {
    Features *features = new Features();

    features->features.push_back(FeatureType::VERSIONS);
    features->features.push_back(FeatureType::PROFILES);
    features->features.push_back(FeatureType::PAIRS);
    features->features.push_back(FeatureType::RATE_LIMIT);

    return features;
}

File* getFile() {
    File *file = new File();

    file->name = "File name";
    file->path = "File path";
    file->hashes.emplace(HashType::MD5, "1234567890ABCDEF1234567890ABCDEF");
    file->hashes.emplace(HashType::SHA1, "1234567890ABCDEF1234567890ABCDEF12345678");
    file->hashes.emplace(HashType::SHA256, "1234567890ABCDEF1234567890ABCDEF1234567890ABCDEF1234567890ABDEF1");

    return file;
}

IdnDomainName* getIdnDomainName() {
    IdnDomainName *idnDomainName = new IdnDomainName();

    idnDomainName->idnDomainName = "IDN Domain name";

    return idnDomainName;
}

IdnEmailAddress* getIdnEmailAddress() {
    IdnEmailAddress *idnEmailAddr = new IdnEmailAddress();

    idnEmailAddr->idnEmailAddress = "IDN Email address";

    return idnEmailAddr;
}

Ipv4Net* getIpv4Net() {
    Ipv4Net *ipv4Net = new Ipv4Net();

    ipv4Net->ipv4Net = "10.0.0.0/24";

    return ipv4Net;
}

Ipv4Connection* getIpv4Connection() {
    Ipv4Connection *ipv4Connection = new Ipv4Connection();

    ipv4Connection->srcAddr = "10.0.0.0/24";
    ipv4Connection->srcPort = 8443;
    ipv4Connection->dstAddr = "10.0.0.0/24";
    ipv4Connection->dstPort = 9443;
    ipv4Connection->protocol = L4ProtocolType::TCP;

    return ipv4Connection;
}

Ipv6Net* getIpv6Net() {
    Ipv6Net *ipv6Net = new Ipv6Net();

    ipv6Net->ipv6Net = "AE:00:E4:F1:04:65/24";

    return ipv6Net;
}

Ipv6Connection* getIpv6Connection() {
    Ipv6Connection *ipv6Connection = new Ipv6Connection();

    ipv6Connection->srcAddr = "AE:00:E4:F1:04:65/24";
    ipv6Connection->srcPort = 8443;
    ipv6Connection->dstAddr = "AE:00:E4:F1:04:65/24";
    ipv6Connection->dstPort = 9443;
    ipv6Connection->protocol = L4ProtocolType::TCP;

    return ipv6Connection;
}

Iri* getIri() {
    Iri *iri = new Iri();

    iri->iri = "My IRI identifier";

    return iri;
}

MacAddress* getMacAddress() {
    MacAddress *macAddress = new MacAddress();

    macAddress->macAddress = "This is my mac address";

    return macAddress;
}

Process* getProcess() {
    Process *parent = new Process();

    parent->pid = 43521;
    parent->name = "Process parent name";
    parent->cwd = "Process parent CWD";

    Process *process = new Process();

    process->pid = 12354;
    process->name = "Process name";
    process->cwd = "Process CWD";
    process->executable = getFile();
    process->parent = parent;
    process->commandLine = "Process command line statement";

    return process;
}

Properties* getProperties() {
    Properties *properties = new Properties();

    properties->properties.push_back("Tag1");
    properties->properties.push_back("Tag2");
    properties->properties.push_back("Tag3");
    properties->properties.push_back("Tag4");

    return properties;
}

URI* getUri() {
    URI *uri = new URI();

    uri->uri = "www.myuri.com";

    return uri;
}

Target getTarget() {
    Target target;

    target.artifact = getArtifact();
    target.device = getDevice();
    target.domainName = getDomainName();
    target.emailAddress = getEmailAddress();
    target.features = getFeatures();
    target.file = getFile();
    target.idnDomainName = getIdnDomainName();
    target.idnEmailAddress = getIdnEmailAddress();
    target.ipv4Net = getIpv4Net();
    target.ipv4Connection = getIpv4Connection();
    target.ipv6Net = getIpv6Net();
    target.ipv6Connection = getIpv6Connection();
    target.iri = getIri();
    target.macAddress = getMacAddress();
    target.process = getProcess();
    target.properties = getProperties();
    target.uri = getUri();

    return target;
}

Args getArgs() {
    Args args;

    args.addStartDuration(1568209029693L, 30 * 1000L);

    return args;
}

TEST_F(TestMessage, test) {
    OpenC2Message msg;
    msg.action = ActionType::CREATE;
    msg.target = getTarget();
    msg.args = getArgs();
    msg.commandId = "My command id is here";

    std::cout << JsonFormatter::getJson(msg, false) << std::endl;

    ASSERT_EQ(JsonFormatter::removePrettyFormatting(expected), JsonFormatter::getJson(msg, false));

    // Just verify that can read in JSON string, testing fields is done
    // by individual test cases for each object
    OpenC2Message msg2 = JsonFormatter::readOpenC2Message(inputJson);

    ASSERT_EQ(msg.commandId, msg2.commandId);
}
