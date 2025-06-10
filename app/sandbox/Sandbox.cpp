#include "SGBrowser.h"

#include <iostream>

class Sandbox : public SG::Application {
public:
    Sandbox() {
        std::cout << "Sandbox created!\n";
    }
};

SG::Application* SG::CreateApplication() {
    return new Sandbox();
}