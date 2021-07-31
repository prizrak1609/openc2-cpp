#include "args.h"

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
