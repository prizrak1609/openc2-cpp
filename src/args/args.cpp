#include "args.h"

using namespace OC;

void OC::Args::addStart(std::time_t startTime)
{
    this->startTime = startTime;
    this->stopTime = -1L;
    this->duration = -1L;
}

void OC::Args::addStartStop(std::time_t startTime, std::time_t stopTime)
{
    this->startTime = startTime;
    if (stopTime > startTime) {
        this->stopTime = stopTime;
        this->duration = stopTime - startTime;
    } else {
        this->stopTime = -1L;
        this->duration = -1L;
    }
}

void OC::Args::addStartDuration(std::time_t startTime, std::time_t duration)
{
    this->startTime = startTime;
    this->stopTime = startTime + duration;
    this->duration = duration;
}

void OC::Args::addStop(std::time_t stopTime)
{
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    this->startTime = now;
    this->stopTime = stopTime;
    this->duration = stopTime - now;
}

void OC::Args::addStopDuration(std::time_t stopTime, std::time_t duration)
{
    this->startTime = stopTime - duration;
    this->stopTime = stopTime;
    this->duration = duration;
}

void OC::Args::addDuration(std::time_t duration)
{
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    this->startTime = now;
    this->stopTime = now + duration;
    this->duration = duration;
}

void OC::to_json(nlohmann::json &json, const Args &item)
{
    json["start_time"] = item.startTime;
    json["stop_time"] = item.stopTime;
    json["response_requested"] = item.responseRequested;
    json["duration"] = item.duration;
}

void from_json(const nlohmann::json &result, Args &args)
{
    args.startTime = result["start_time"].get<time_t>();
    args.stopTime = result["stop_time"].get<time_t>();
    args.responseRequested = result["response_requested"].get<std::string>();
    args.duration = result["duration"].get<time_t>();
}
