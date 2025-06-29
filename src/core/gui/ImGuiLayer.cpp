#include "ImGuiLayer.h"

#include <imgui.h>
#include "backends/imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"
#include "Application.h"
#include "events/BrowserEvents.h"
#include "spdlog/spdlog.h"

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
        
        float top_bar_height = 40.0f;
        auto top_bar_size = ImVec2(Application::get().getWindow().getWidth(), top_bar_height); 
        auto top_bar_pos = ImVec2(0.0f, 0.0f);
        
        ImGui::SetNextWindowSize(top_bar_size);
        ImGui::SetNextWindowPos(top_bar_pos);
        
        ImGui::Begin("TopBar", nullptr, top_bar_flags);
        
        static char searchBuffer[128] = "";
        ImGui::Text("Search:");
        ImGui::SameLine();
        ImGui::SetNextItemWidth(200);
        if (ImGui::InputTextWithHint("##search", "http://...", searchBuffer, IM_ARRAYSIZE(searchBuffer), ImGuiInputTextFlags_EnterReturnsTrue)) {
            SearchUrlEvent event{searchBuffer};
            callback(event);
        }
        
        ImGui::End(); // TopBar
        
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
    
    void ImGuiLayer::onDetach() {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }
    
    void ImGuiLayer::onEvent(SG::Event &event) {}
    
    void ImGuiLayer::setCallback(std::function<void(SG::Event &)> _callback) {
        this->callback = _callback;
    }

    std::unique_ptr<ImGuiLayer> ImGuiLayer::create() {
        return std::make_unique<ImGuiLayer>();
    }
}
