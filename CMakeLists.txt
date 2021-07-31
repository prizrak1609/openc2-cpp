cmake_minimum_required(VERSION 3.5)

project(OpenC2cpp LANGUAGES CXX)

include(${CMAKE_BINARY_DIR}/conan-dependencies/conan_paths.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(jsonformoderncpp REQUIRED)

include_directories(${jsonformoderncpp_INCLUDES}
    inc/actuators
    inc/args
    inc/interfaces
    inc/json
    inc/utilities
    inc/targets
    inc
    )

add_library(OpenC2cpp STATIC
            src/openc2response.cpp
            src/openc2message.cpp
            src/actuators/actuatortype.cpp
            src/args/args.cpp
            src/interfaces/validation.cpp
            src/json/jsonformatter.cpp
            src/utilities/payload.cpp
            src/targets/artifact.cpp
            src/targets/device.cpp
            src/targets/domainname.cpp
            src/targets/emailaddress.cpp
            src/targets/features.cpp
            src/targets/file.cpp
            src/targets/idndomainname.cpp
            src/targets/idnemailaddress.cpp
            src/targets/ipv4connection.cpp
            src/targets/ipv4net.cpp
            src/targets/ipv6connection.cpp
            src/targets/ipv6net.cpp
            src/targets/iri.cpp
            src/targets/macaddress.cpp
            )
