#include "openc2response.h"

using namespace OC;

OpenC2Response& OpenC2Response::addResults(const std::string &key, std::any value) {
    results.emplace(key, value);
    return *this;
}

template<>
std::string JSON::toJson<>(const OpenC2Response& item)
{
    nlohmann::json json;
    json["status"] = item.status;
    if (!item.statusText.empty()) {
        json["status_text"] = item.statusText;
    }
    if (!item.results.empty()) {
        nlohmann::json results;
        for (const auto &pair : item.results) {
            results[pair.first] = toJson(pair.second);
        }
        json["results"] = results;
    }

    return json;
}

template<>
OpenC2Response JSON::fromJson<>(std::string_view json)
{
    nlohmann::json result = nlohmann::json::parse(json);

    OpenC2Response response;
    response.status = result["status"];
    if (result.contains("status_text")) {
        response.statusText = result["status_text"].get<std::string>();
    }
    if (result.contains("results")) {
        for (auto &[key, value] : result["results"].items()) {
            response.addResults(key, value);
        }
    }
    return response;
}
