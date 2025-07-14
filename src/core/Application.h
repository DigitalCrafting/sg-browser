#ifndef SG_BROWSER_APPLICATION_H
#define SG_BROWSER_APPLICATION_H

#include "Core.h"
#include "window/Window.h"
#include "gui/ImGuiLayer.h"
#include "renderer/HtmlRendererLayer.h"

namespace SG {
    class Application {
    public:
        Application();

        void run();

        inline static Application& get() { return *s_Instance; };
        inline Window& getWindow() const { return *m_Window; }

    protected:
        static Application* s_Instance;
        std::unique_ptr<Window> m_Window;
        std::unique_ptr<ImGuiLayer> m_Gui;
        std::unique_ptr<HtmlRendererLayer> m_HtmlRenderer;
    };

    // To be defined in client
    Application *CreateApplication();
}


#endif //SG_BROWSER_APPLICATION_H
