#pragma once

#include <string>

namespace OC {

    struct L4ProtocolType
    {
        static const std::string ICMP;
        static const std::string TCP;
        static const std::string UDP;
        static const std::string SCTP;
    };

}
