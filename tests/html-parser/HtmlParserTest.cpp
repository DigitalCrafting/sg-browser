#include "catch2/catch_test_macros.hpp"

#include <iostream>
#include "parser/HtmlParser.h"

TEST_CASE("should call parse from Html")
{
    std::string code = "Hello Html!";
    
    auto stdoutBuffer = std::cout.rdbuf();
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());

    Html::parse(code);

    std::cout.rdbuf(stdoutBuffer);
    REQUIRE(oss.str() == (code + "\n"));
}