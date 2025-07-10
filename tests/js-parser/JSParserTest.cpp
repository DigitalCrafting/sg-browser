#include "catch2/catch_test_macros.hpp"

#include <iostream>
#include "GSParser.h"

TEST_CASE("should call parse from GS")
{
    std::string code = "Hello GS!";

    auto stdoutBuffer = std::cout.rdbuf();
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());

    GS::parse(code);

    std::cout.rdbuf(stdoutBuffer);
    REQUIRE(oss.str() == (code + "\n"));
}