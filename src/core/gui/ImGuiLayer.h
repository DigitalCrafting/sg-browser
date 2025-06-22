#ifndef SG_BROWSER_IMGUILAYER_H
#define SG_BROWSER_IMGUILAYER_H

#include "events/Event.h"

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
    };
}


#endif //SG_BROWSER_IMGUILAYER_H
