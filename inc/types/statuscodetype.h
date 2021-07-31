#pragma once

#include <string>

namespace OC {

    struct StatusCodeType
    {
        static const int PROCESSING;
        static const int OK;
//        static const int MOVED;
        static const int BAD_REQUEST;
        static const int UNAUTHORIZED;
        static const int FORBIDDEN;
        static const int NOT_FOUND;
        static const int INTERNAL_ERROR;
        static const int NOT_IMPLEMENTED;
        static const int SERVICE_UNAVAILABLE;
    };

}
