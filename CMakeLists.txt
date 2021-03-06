cmake_minimum_required(VERSION 3.14)

project(OpenC2cpp LANGUAGES CXX)

include(${CMAKE_BINARY_DIR}/conan-dependencies/conan_paths.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

enable_testing()

find_package(jsonformoderncpp REQUIRED)
find_package(GTest REQUIRED)

include_directories(${jsonformoderncpp_INCLUDES}
    ${GTest_INCLUDES}
    ${gtest_SOURCE_DIR}/include
    ${gtest_SOURCE_DIR}
    inc/actuators
    inc/args
    inc/interfaces
    inc/json
    inc/utilities
    inc/targets
    inc/types
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
            src/targets/process.cpp
            src/targets/properties.cpp
            src/targets/uri.cpp
            src/targets/target.cpp
            src/types/actiontype.cpp
            src/types/argsresponsetype.cpp
            src/types/featuretype.cpp
            src/types/hashtype.cpp
            src/types/l4protocoltype.cpp
            src/types/statuscodetype.cpp
            )

add_executable(runUnitTests
    tests/testResponse.cpp
    tests/OpenC2MessageTest.cpp
)

target_link_libraries(runUnitTests ${GTest_LIBS} OpenC2cpp)

add_test(runUnitTests runUnitTests)
