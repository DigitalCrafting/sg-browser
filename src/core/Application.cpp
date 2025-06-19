#include "Application.h"
#include <iostream>

namespace SG {
    void glfw_error_callback(int error, const char *description) {
        std::cerr << "GLFW Error " << error << ": " << description << std::endl;
    }
    
    Application* Application::s_Instance = nullptr;

    Application::Application() {
        s_Instance = this;
        glfwSetErrorCallback(glfw_error_callback);

        if (!glfwInit()) {
            std::cerr << "Failed to initialize GLFW" << std::endl;
            // return -1;
            // TODO THROW
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(800, 600, "Minimal ImGui Example", nullptr, nullptr);
        if (!window) {
            std::cerr << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            // return -1;
            // TODO THROW
        }

        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);

        if (!gladLoadGL(glfwGetProcAddress)) {
            std::cerr << "Failed to initialize GLAD" << std::endl;
            // return -1;
            // TODO THROW
        }

        std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
    }

    Application::~Application() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void Application::run() {
        while (!glfwWindowShouldClose(window)) {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // Clear background
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }
}