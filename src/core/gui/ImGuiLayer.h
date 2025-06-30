#ifndef SG_BROWSER_IMGUILAYER_H
#define SG_BROWSER_IMGUILAYER_H

#include "events/Events.h"
#include "imgui.h"

#include <functional>

namespace SG {
    class ImGuiLayer {
    public:
        ImGuiLayer();
        ~ImGuiLayer();
        
        void onAttach(GLFWwindow* wwindow);
        void onUpdate();
        void onDetach();
        void onEvent(Event& event);
        void setCallback(std::function<void(SG::Event&)> _callback);

        static std::unique_ptr<ImGuiLayer> create();
    private:
        constexpr static auto top_bar_flags =
                ImGuiWindowFlags_NoResize |
                ImGuiWindowFlags_NoMove |
                ImGuiWindowFlags_NoCollapse |
                ImGuiWindowFlags_NoScrollbar |
                ImGuiWindowFlags_NoTitleBar | 
                ImGuiWindowFlags_NoSavedSettings;

        std::function<void(SG::Event&)> callback;
    };
}


#endif //SG_BROWSER_IMGUILAYER_H
