#ifndef SG_BROWSER_APPLICATION_H
#define SG_BROWSER_APPLICATION_H

#include "Core.h"
#include "window/Window.h"

namespace SG {
    class Application {
    public:
        Application();
        virtual ~Application();

        void run();

        inline static Application* get() { return s_Instance; };
    private:
        static Application* s_Instance;
        std::unique_ptr<Window> m_Window;
    };

    // To be defined in client
    Application *CreateApplication();
}


#endif //SG_BROWSER_APPLICATION_H
