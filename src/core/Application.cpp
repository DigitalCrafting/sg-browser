#include "Application.h"

namespace SG {
    Application* Application::s_Instance = nullptr;

    Application::Application() {
        s_Instance = this;
        m_Window = Window::create();
        m_Gui = ImGuiLayer::create();
    }

    void Application::run() {
        m_Gui->onAttach(m_Window->getWindowHandle());
        while (!m_Window->shouldClose()) {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // Clear background
            glClear(GL_COLOR_BUFFER_BIT);
     
            m_Gui->onUpdate();
            m_Window->update();
        }
        m_Gui->onDetach();
    }
}