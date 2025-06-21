#include "Window.h"

#include <iostream>

namespace SG {
    static void glfw_error_callback(int error, const char *description) {
        std::cerr << "GLFW Error " << error << ": " << description << std::endl;
    }
    
    std::unique_ptr<Window> Window::create(const WindowProps &props) {
        return std::make_unique<Window>(props);    
    }
    
    Window::Window(const WindowProps& props) {
        init(props);
        startup();
    }
    
    Window::~Window() {
        shutdown();
    }

    void Window::init(const SG::WindowProps &props) {
        data.title = props.title;
        data.height = props.height;
        data.width = props.width;
        data.vSync = props.vSync;
    }
    
    void Window::startup() {
        glfwSetErrorCallback(glfw_error_callback);

        if (!glfwInit()) {
            std::cerr << "Failed to initialize GLFW" << std::endl;
            // return -1;
            // TODO THROW
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow((int) data.width, (int) data.height, data.title.c_str(), nullptr, nullptr);
        if (!window) {
            std::cerr << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            // return -1;
            // TODO THROW
        }

        glfwMakeContextCurrent(window);
        glfwSwapInterval(data.vSync);

        if (!gladLoadGL(glfwGetProcAddress)) {
            std::cerr << "Failed to initialize GLAD" << std::endl;
            // return -1;
            // TODO THROW
        }

        std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
    }
    
    void Window::shutdown() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }
    
    void Window::update() {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    void Window::setVSync(bool enabled) {
        if (enabled) {
            glfwSwapInterval(1);
        } else {
            glfwSwapInterval(0);
        }
        data.vSync = enabled;
    }
    
    bool Window::isVSync() {
        return data.vSync;
    }
}