#include "catch2/catch_test_macros.hpp"

#include <iostream>
#include "JSParser.h"

TEST_CASE("should call parse from JSParser")
{
    std::string code = "Hello JSParser!";

    auto stdoutBuffer = std::cout.rdbuf();
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());

    JSParser::parse(code);

    std::cout.rdbuf(stdoutBuffer);
    REQUIRE(oss.str() == (code + "\n"));
}