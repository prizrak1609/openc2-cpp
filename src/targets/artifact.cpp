#include "artifact.h"

using namespace OC;

static const std::string MD5_PATTERN = "^[A-F0-9]{32}$";
static const std::string SHA1_PATTERN = "^[A-F0-9]{40}$";
static const std::string SHA256_PATTERN = "^[A-F0-9]{64}$";

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

void OC::to_json(nlohmann::json &json, const Artifact &item)
{
    json["mime_type"] = item.mimeType;
    json["payload"] = item.payload;
    json["hashes"] = item.hashes;
}

void OC::from_json(const nlohmann::json &result, Artifact &artifact)
{
    artifact.mimeType = result["mime_type"].get<std::string>();
    artifact.payload = result["payload"].get<Payload>();
    artifact.hashes = result["hashes"].get<std::unordered_map<std::string, std::string>>();
}
