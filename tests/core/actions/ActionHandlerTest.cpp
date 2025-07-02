#include "catch2/catch_test_macros.hpp"

#include <iostream>
#include <vector>
#include <string>
#include "actions/Actions.h"
#include "actions/BrowserActions.h"

TEST_CASE("should handle action") {
    std::string url = "This is searched";
    SG::SearchUrlAction action{url.c_str()};

    auto stdoutBuffer = std::cout.rdbuf();
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());

    SG::ActionHandler<SG::SearchUrlAction> handler{
            [](SG::SearchUrlAction &e) { 
                std::cout << e.getUrl();
            }
    };
    
    handler.handleAction(action);
    
    std::cout.rdbuf(stdoutBuffer);
    REQUIRE(oss.str() == url);
}