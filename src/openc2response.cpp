#include "openc2response.h"

using namespace OC;

OpenC2Response& OpenC2Response::addResults(const std::string &key, std::any value) {
    results.emplace(key, value);
    return *this;
}
