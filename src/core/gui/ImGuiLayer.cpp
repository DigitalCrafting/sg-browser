#include "ImGuiLayer.h"

#include <imgui.h>
#include "backends/imgui_impl_opengl3.h"
#include "Application.h"
#include "imgui_impl_glfw.h"

namespace SG {
    ImGuiLayer::ImGuiLayer() {
    }
    
    ImGuiLayer::~ImGuiLayer() {
    }
    
    void ImGuiLayer::onAttach(GLFWwindow* window) {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui::StyleColorsDark();
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 460");
    }

    void ImGuiLayer::onUpdate() {
        ImGui_ImplGlfw_NewFrame();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();
        
        ImGui::Text("This is a minimal ImGui example."); // Text inside the window

        // Render ImGui
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
    
    void ImGuiLayer::onDetach() {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }
    
    void ImGuiLayer::onEvent(SG::Event &event) {}

    std::unique_ptr<ImGuiLayer> ImGuiLayer::create() {
        return std::make_unique<ImGuiLayer>();
    }
}
