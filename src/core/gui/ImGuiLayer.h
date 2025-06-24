#ifndef SG_BROWSER_IMGUILAYER_H
#define SG_BROWSER_IMGUILAYER_H

#include "events/Event.h"
#include "imgui.h"

namespace SG {
    class ImGuiLayer {
    public:
        ImGuiLayer();
        ~ImGuiLayer();
        
        void onAttach(GLFWwindow* wwindow);
        void onUpdate();
        void onDetach();
        void onEvent(Event& event);

        static std::unique_ptr<ImGuiLayer> create();
    private:
        constexpr static auto top_bar_flags =
                ImGuiWindowFlags_NoResize |
                ImGuiWindowFlags_NoMove |
                ImGuiWindowFlags_NoCollapse |
                ImGuiWindowFlags_NoScrollbar |
                ImGuiWindowFlags_NoTitleBar | 
                ImGuiWindowFlags_NoSavedSettings;

    };
}


#endif //SG_BROWSER_IMGUILAYER_H
