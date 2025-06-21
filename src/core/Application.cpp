#include "Application.h"

namespace SG {
    Application* Application::s_Instance = nullptr;

    Application::Application() {
        m_Window = Window::create();
    }

    Application::~Application() {
    }

    void Application::run() {
        while (!m_Window->shouldClose()) {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // Clear background
            glClear(GL_COLOR_BUFFER_BIT);
     
            m_Window->update();
        }
    }
}