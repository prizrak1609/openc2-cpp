#include <gtest/gtest.h>
#include <string>
#include <iostream>

#include "openc2response.h"
#include "statuscodetype.h"
#include "jsonformatter.h"

using namespace OC;

class TestResponse : public ::testing::Test {
};

TEST_F(TestResponse, OpenC2Response_convert_to_JSON) {
    std::string expected = R"===({"results":{"tags":["Tag1","Tag2","Tag3","Tag4","Tag5"],"version":"1.0"},"status":404,"status_text":"Couldn't find what you want"})===";

    OpenC2Response response;
    std::string tags[] = {"Tag1", "Tag2","Tag3","Tag4","Tag5"};

    response.status = StatusCodeType::NOT_FOUND;
    response.statusText = "Couldn't find what you want";
    response.addResults("version", "1.0");
    response.addResults("tags", tags);

    std::cout << JsonFormatter::getJson(response, true) << std::endl;

    ASSERT_EQ(expected, JsonFormatter::getJson(response, false));
}

TEST_F(TestResponse, OpenC2Response_convert_from_JSON) {
    std::string inputJson = R"===(
{
  "status_text":"Couldn't find what you want",
  "status":404,
  "results":{
    "version":"1.0",
    "tags":[
      "Tag1","Tag2","Tag3","Tag4","Tag5"
    ]
  }
})===";

    OpenC2Response response2 = JsonFormatter::readOpenC2Response(inputJson);

    ASSERT_EQ(404, response2.status);
    ASSERT_EQ("Couldn't find what you want", response2.statusText);
    ASSERT_EQ("1.0", response2.results["version"].get<std::string>());
}
