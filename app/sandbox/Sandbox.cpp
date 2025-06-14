#include "SGBrowser.h"

#include <iostream>
#include <vector>
#include "layers/Layer.h"


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
};

void FirstLayer_onAttach(void* ctx) {
    static_cast<FirstLayer*>(ctx)->onAttach();
}

void SecondLayer_onAttach(void* ctx) {
    static_cast<SecondLayer*>(ctx)->onAttach();
}

class Sandbox : public SG::Application {
public:
    Sandbox() {
        std::cout << "Sandbox created!\n";
        
        FirstLayer firstLayer;
        SecondLayer secondLayer;
        
        std::vector<SG::LayerInterface> layers;
        
        layers.push_back(SG::LayerInterface{
                .onAttach = FirstLayer_onAttach,
                .onDetach = nullptr,
                .onUpdate = nullptr,
                .onEvent = nullptr,
                .context = &firstLayer
        });
        layers.push_back(SG::LayerInterface{
                .onAttach = SecondLayer_onAttach,
                .onDetach = nullptr,
                .onUpdate = nullptr,
                .onEvent = nullptr,
                .context = &secondLayer
        });
        
        for (auto& layer : layers) {
            layer.onAttach(layer.context);
        }
    }
};

SG::Application* SG::CreateApplication() {
    return new Sandbox();
}