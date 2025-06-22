#ifndef SG_BROWSER_WINDOW_H
#define SG_BROWSER_WINDOW_H

#include "Core.h"
#include <string>

namespace SG {
    struct WindowProps {
        std::string title;
        unsigned int width;
        unsigned int height;
        bool vSync;
        
        WindowProps(
                const std::string& _title = "SG Browser",
                unsigned int _width = 1280,
                unsigned int _height = 720,
                bool _vSync = 1
        ): title(_title), width(_width), height(_height), vSync(_vSync) {}
    };
    
    class Window {
    public:
        Window(const WindowProps& props);
        ~Window();
        
        void update();
        void setVSync(bool enabled);
        bool isVSync();
        
        inline bool shouldClose() {
            return glfwWindowShouldClose(window);
        } 
        
        inline unsigned int getWidth() const {
            return data.width;
        };
        
        inline unsigned int getHeight() const {
            return data.height;
        };
        
        inline GLFWwindow* getWindowHandle() { return window; }

        static std::unique_ptr<Window> create(const WindowProps& props = WindowProps());
    private:
        GLFWwindow* window;
        WindowProps data;
        
    private:
        void init(const WindowProps& props);
        void startup();
        void shutdown();
    };
}

#endif //SG_BROWSER_WINDOW_H
