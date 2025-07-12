#ifndef SG_BROWSER_IMGUILAYER_H
#define SG_BROWSER_IMGUILAYER_H

#include "events/Events.h"
#include "imgui.h"
#include "actions/Actions.h"
#include "actions/BrowserActions.h"

#include <functional>
#include <optional>

namespace SG {
    class ImGuiLayer {
    public:
        ImGuiLayer();
        ~ImGuiLayer();
        
        void onAttach(GLFWwindow* window);
        void onUpdate();
        void onDetach();
        void onEvent(Event& event);
        void setSearchCallback(SG::ActionHandler<SG::SearchUrlAction>* _handler);

        static std::unique_ptr<ImGuiLayer> create();
    private:
        constexpr static auto top_bar_flags =
                ImGuiWindowFlags_NoResize |
                ImGuiWindowFlags_NoMove |
                ImGuiWindowFlags_NoCollapse |
                ImGuiWindowFlags_NoScrollbar |
                ImGuiWindowFlags_NoTitleBar | 
                ImGuiWindowFlags_NoSavedSettings;

        SG::ActionHandler<SG::SearchUrlAction>* searchHandler = nullptr;
        
    private:
        void triggerSearch(SG::SearchUrlAction& event) {
            if (searchHandler) {
                searchHandler->handleAction(event);
            }
        }
    };
}


#endif //SG_BROWSER_IMGUILAYER_H
