#include "artifact.h"

using namespace OC;
using namespace JSON;

static const std::string MD5_PATTERN = "^[A-F0-9]{32}$";
static const std::string SHA1_PATTERN = "^[A-F0-9]{40}$";
static const std::string SHA256_PATTERN = "^[A-F0-9]{64}$";

template<>
std::string OC::JSON::toJson<>(const Artifact& item)
{
    nlohmann::json json;
    json["mimeType"] = item.mimeType;
    json["payload"] = toJson(item.payload);
    json["hashes"] = item.hashes;
    return json;
}

template<>
OC::Artifact OC::JSON::fromJson<>(std::string_view json)
{
    nlohmann::json result = nlohmann::json::parse(json);

    Artifact artifact;
    artifact.mimeType = result["mimeType"].get<std::string>();
    artifact.payload = fromJson<Payload>(result["payload"].get<std::string>());
    artifact.hashes = result["hashes"].get<std::unordered_map<std::string, std::string>>();

    return artifact;
}

OC::Artifact& OC::Artifact::addHashes(std::string_view key, std::string_view hash, bool& error)
{
    error = false;
    if (!validateHash(key, hash)) {
        error = true;
        return *this;
    }

    hashes.emplace(key, hash);
    return *this;
}

bool OC::Artifact::validateHash(std::string_view key, std::string_view value)
{
    return true;
    //    if (key == "md5") {
    //        return Pattern.compile(MD5_PATTERN).matcher(value).matches();
    //    } else if (key == "sha1") {
    //        return Pattern.compile(SHA1_PATTERN).matcher(value).matches();
    //    } else if (key == "sha256") {
    //        return Pattern.compile(SHA256_PATTERN).matcher(value).matches();
    //    }

    //    return false;
}

bool OC::Artifact::isValid()
{
    for (const auto &pair : hashes) {
        if (!validateHash(pair.first, hashes[pair.first]))
            return false;
    }

    return true;
}
