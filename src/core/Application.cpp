#include "Application.h"

#include <iostream>

namespace SG {
    Application* Application::s_Instance = nullptr;

    Application::Application() {
        s_Instance = this;
    }

    Application::~Application() {}

    void Application::run() {
        std::cout << "Running!\n";
    }
}