#include <iostream>
#include <vector>
#include "Application.h"
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

int main(int argc, char** args) {
    auto app = new Sandbox();
    app->run();
    delete app;
    return 0;
}