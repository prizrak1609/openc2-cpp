#include "openc2response.h"

using namespace OC;

OpenC2Response& OpenC2Response::addResults(const std::string &key, std::any value) {
    results.emplace(key, value);
    return *this;
}

void to_json(nlohmann::json &json, const OpenC2Response &item)
{
    json["status"] = item.status;
    if (!item.statusText.empty()) {
        json["status_text"] = item.statusText;
    }
    if (!item.results.empty()) {
        nlohmann::json results;
        for (const auto &pair : item.results) {
            results[pair.first] = pair.second;
        }
        json["results"] = results;
    }
}

void from_json(const nlohmann::json &result, OpenC2Response &response)
{
    response.status = result["status"];
    if (result.contains("status_text")) {
        response.statusText = result["status_text"].get<std::string>();
    }
    if (result.contains("results")) {
        for (auto &[key, value] : result["results"].items()) {
            response.addResults(key, value);
        }
    }
}
