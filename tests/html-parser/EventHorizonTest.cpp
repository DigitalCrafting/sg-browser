#include "catch2/catch_test_macros.hpp"

#include <iostream>
#include "EventHorizon.h"

TEST_CASE("should call parse from EventHorizon")
{
    std::string code = "Hello EventHorizon!";
    
    auto stdoutBuffer = std::cout.rdbuf();
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());

    EventHorizon::parse(code);

    std::cout.rdbuf(stdoutBuffer);
    REQUIRE(oss.str() == (code + "\n"));
}