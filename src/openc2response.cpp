#include "openc2response.h"

using namespace OC;

OpenC2Response& OpenC2Response::setStatus(unsigned int status)
{
    this->status = status;
    return *this;
}

OpenC2Response& OpenC2Response::setStatusText(std::string_view text)
{
    statusText = text;
    return *this;
}

OpenC2Response& OpenC2Response::addResults(const std::string &key, std::any value) {
    results.emplace(key, value);
    return *this;
}
