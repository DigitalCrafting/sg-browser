#include "Window.h"

#include "spdlog/spdlog.h"

namespace SG {
    static void glfw_error_callback(int error, const char *description) {
        spdlog::error("GLFW Error {}: {}", error, description);
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
            spdlog::error("Failed to initialize GLFW");
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow((int) data.width, (int) data.height, data.title.c_str(), nullptr, nullptr);
        if (!window) {
            spdlog::error("Failed to create GLFW window");
            glfwTerminate();
        }

        glfwMakeContextCurrent(window);
        glfwSwapInterval(data.vSync);

        if (!gladLoadGL(glfwGetProcAddress)) {
            spdlog::error("Failed to initialize GLAD");
        }

        spdlog::info("OpenGL Version: {}", (char*)glGetString(GL_VERSION));
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