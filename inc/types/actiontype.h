#pragma once

#include <string>

namespace OC {

    struct ActionType
    {
        static const std::string SCAN;
        static const std::string LOCATE;
        static const std::string QUERY;
        static const std::string DENY;
        static const std::string CONTAIN;
        static const std::string ALLOW;
        static const std::string START;
        static const std::string STOP;
        static const std::string RESTART;
        static const std::string CANCEL;
        static const std::string SET;
        static const std::string UPDATE;
        static const std::string REDIRECT;
        static const std::string CREATE;
        static const std::string DELETE;
        static const std::string DETONATE;
        static const std::string RESTORE;
        static const std::string COPY;
        static const std::string INVESTIGATE;
        static const std::string REMEDIATE;
    };

}
