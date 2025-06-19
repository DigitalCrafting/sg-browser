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


class Sandbox : public SG::Application {
public:
    Sandbox() {
        std::cout << "Sandbox created!\n";
        
        SG::LayerWrapper<FirstLayer> firstLayer;
        
        SG::LayerStack layerStack;
        
        layerStack.pushLayer(firstLayer.getHandle());
    }
};

SG::Application* SG::CreateApplication() {
    return new Sandbox();
}