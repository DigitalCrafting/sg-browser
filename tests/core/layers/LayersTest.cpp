#include "catch2/catch_test_macros.hpp"

#include <iostream>
#include <vector>
#include "layers/LayerWrapper.h"
#include "layers/LayerStack.h"


struct FirstLayer {
    void onAttach() {
        std::cout << "First layer onAttach!\n";
    }

    void onDetach() {
        std::cout << "First layer onDetach!\n";
    }

    void onUpdate() {
        std::cout << "First layer onUpdate!\n";
    }

    void onEvent(SG::Event& event) {
        std::cout << "First layer onEvent!\n";
    }
};

struct SecondLayer {
    void onAttach() {
        std::cout << "Second layer onAttach!\n";
    }

    void onDetach() {
        std::cout << "Second layer onDetach!\n";
    }

    void onUpdate() {
        std::cout << "Second layer onUpdate!\n";
    }

    void onEvent(SG::Event& event) {
        std::cout << "Second layer onEvent!\n";
    }
};

TEST_CASE("should add and attach layer")
{
    SG::LayerWrapper<FirstLayer> firstLayer;
    SG::LayerWrapper<SecondLayer> secondLayer;

    SG::LayerStack layerStack;

    auto stdoutBuffer = std::cout.rdbuf();
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());
    
    layerStack.pushLayer(firstLayer.getHandle());

    std::cout.rdbuf(stdoutBuffer);
    REQUIRE(oss.str() == "First layer onAttach!\n");
}

TEST_CASE("should remove and detach layer")
{
    SG::LayerWrapper<FirstLayer> firstLayer;
    SG::LayerWrapper<SecondLayer> secondLayer;

    SG::LayerStack layerStack;
    layerStack.pushLayer(firstLayer.getHandle());

    auto stdoutBuffer = std::cout.rdbuf();
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());

    layerStack.popLayer(firstLayer.getHandle());

    std::cout.rdbuf(stdoutBuffer);
    REQUIRE(oss.str() == "First layer onDetach!\n");
}