#include "catch2/catch_test_macros.hpp"

#include <iostream>
#include <vector>
#include "events/Event.h"
#include "events/EventDispatcher.h"
#include "events/MouseEvent.h"

TEST_CASE("should dispatch event") {
    SG::MouseMoveEvent event;
    SG::EventDispatcher dispatcher(event);

    auto stdoutBuffer = std::cout.rdbuf();
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());

    bool handled = dispatcher.dispatch<SG::MouseMoveEvent>(
            [](SG::MouseMoveEvent &e) {
                std::cout << e;
                return true;
            }
    );

    std::cout.rdbuf(stdoutBuffer);
    REQUIRE(oss.str() == event.name);
    REQUIRE(handled == true);
}