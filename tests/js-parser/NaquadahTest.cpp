#include "catch2/catch_test_macros.hpp"

#include <iostream>
#include "Naquadah.h"

TEST_CASE("should call parse from Naquadah")
{
    std::string code = "Hello Naquadah!";

    auto stdoutBuffer = std::cout.rdbuf();
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());

    Naquadah::parse(code);

    std::cout.rdbuf(stdoutBuffer);
    REQUIRE(oss.str() == (code + "\n"));
}