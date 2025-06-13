#include "SGBrowser.h"

#include <iostream>
#include "layers/Layer.h"


struct FirstLayer : public SG::Layer<FirstLayer> {
    void do_onAttach() {
        std::cout << "First layer onAttach!\n";
    }
    
    void do_onDetach() {
        std::cout << "First layer onDetach!\n";
    }
    
    void do_onUpdate() {
        std::cout << "First layer onUpdate!\n";
    }
};

struct SecondLayer : public SG::Layer<SecondLayer> {
    void do_onAttach() {
        std::cout << "Second layer onAttach!\n";
    }
    
    void do_onDetach() {
        std::cout << "Second layer onDetach!\n";
    }
    
    void do_onUpdate() {
        std::cout << "Second layer onUpdate!\n";
    }
};

class Sandbox : public SG::Application {
public:
    Sandbox() {
        std::cout << "Sandbox created!\n";
        
        FirstLayer firstLayer;
        SecondLayer secondLayer;
    }
};

SG::Application* SG::CreateApplication() {
    return new Sandbox();
}