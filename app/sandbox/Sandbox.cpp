#include "SGBrowser.h"

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

class Sandbox : public SG::Application {
public:
    Sandbox() {
        std::cout << "Sandbox created!\n";
        
        SG::LayerWrapper<FirstLayer> firstLayer;
        SG::LayerWrapper<SecondLayer> secondLayer;
        
        SG::LayerStack layerStack;
        
        layerStack.pushLayer(firstLayer.getHandle());
        layerStack.pushLayer(secondLayer.getHandle());
    }
};

SG::Application* SG::CreateApplication() {
    return new Sandbox();
}