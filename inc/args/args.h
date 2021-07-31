#pragma once

#include <string>
#include <json_dto/pub.hpp>
#include <chrono>

#include "ArgsResponseType.h"

namespace OC {

    struct Args
    {
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

}

namespace json_dto {

    template<typename Json_Io>
    void json_io(Json_Io &io, OC::Args &args) {
        io & json_dto::optional("start_time", args.startTime, -1L)
                & json_dto::optional("stop_time", args.stopTime, -1L)
                & json_dto::optional("duration", args.duration, -1L)
                & json_dto::optional("response_requested", args.responseRequested, ArgsResponseType.COMPLETE);
    }

}
