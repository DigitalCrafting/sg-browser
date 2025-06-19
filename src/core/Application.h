#ifndef SG_BROWSER_APPLICATION_H
#define SG_BROWSER_APPLICATION_H

#include "glad/gl.h"
#include "GLFW/glfw3.h"

namespace SG {
    class Application {
    public:
        Application();
        virtual ~Application();

        void run();

        inline static Application* get() { return s_Instance; };
    private:
        static Application* s_Instance;
        GLFWwindow* window;
    };

    // To be defined in client
    Application *CreateApplication();
}


#endif //SG_BROWSER_APPLICATION_H
