cmake_minimum_required(VERSION 3.5)

project(OpenC2cpp LANGUAGES CXX)

include(${CMAKE_BINARY_DIR}/conan-dependencies/conan_paths.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(json-dto REQUIRED)
find_package(RapidJSON REQUIRED)

include_directories(${json-dto_INCLUDES}
    ${RapidJSON_INCLUDES}
    inc/actuators
    inc/args
    inc
    )

add_library(OpenC2cpp STATIC
            src/openc2response.cpp
            src/openc2message.cpp
            src/actuators/actuatortype.cpp
            src/args/args.cpp
            )
