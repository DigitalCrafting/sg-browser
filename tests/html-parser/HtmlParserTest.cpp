#include "catch2/catch_test_macros.hpp"

#include <iostream>
#include "HtmlParser.h"

TEST_CASE("should call parse from HtmlParser")
{
    std::string code = "Hello HtmlParser!";
    
    auto stdoutBuffer = std::cout.rdbuf();
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());

    HtmlParser::parse(code);

    std::cout.rdbuf(stdoutBuffer);
    REQUIRE(oss.str() == (code + "\n"));
}