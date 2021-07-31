#pragma once

#include <string>
#include <chrono>
#include <nlohmann/json.hpp>

#include "ArgsResponseType.h"

namespace OC {

    struct Args {
            std::time_t startTime = -1L;
            std::time_t stopTime = -1L;
            std::time_t duration = -1L;
            std::string responseRequested = ArgsResponseType.COMPLETE;

            void addStart(std::time_t startTime);
            void addStartStop(std::time_t startTime, std::time_t stopTime);
            void addStartDuration(std::time_t startTime, std::time_t duration);
            void addStop(std::time_t stopTime);
            void addStopDuration(std::time_t stopTime, std::time_t duration);
            void addDuration(std::time_t duration);
    };

    void to_json(nlohmann::json& j, const Args& p);
    void from_json(const nlohmann::json& j, Args& p);

}
