#pragma once

#include <string>

namespace OC {

    /**
     * Definition of all the allowed actuator types as of the 03/27/2017 Openc2 spec
     */
    struct ActuatorType
    {
        static const std::string SLPF;
        //static const std::string ENDPOINT;,
        //static const std::string ENDPOINT_WORKSTATION;
        //static const std::string ENDPOINT_SERVER;
        //static const std::string NETWORK;
        //static const std::string NETWORK_FIREWALL;
        //static const std::string NETWORK_ROUTER;
        //static const std::string NETWORK_PROXY;
        //static const std::string NETWORK_SENSOR;
        //static const std::string NETWORK_HIPS;
        //static const std::string NETWORK_SENSE_MAKING;
        //static const std::string PROCESS;
        //static const std::string PROCESS_ANTI_VIRUS_SCANNER;
        //static const std::string PROCESS_AAA_SERVICE;
        //static const std::string PROCESS_VIRTUALIZATION_SERVICE;
        //static const std::string PROCESS_SANDBOX;
        //static const std::string PROCESS_EMAIL_SERVICE;
        //static const std::string PROCESS_DIRECTORY_SERVICE;
        //static const std::string PROCESS_REMEDIATION_SERVICE;
        //static const std::string PROCESS_LOCATION_SERVICE;
    };

}
