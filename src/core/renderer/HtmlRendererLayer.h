#ifndef SG_BROWSER_RENDERER_LAYER_H
#define SG_BROWSER_RENDERER_LAYER_H

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "events/Events.h"

namespace SG {
    class HtmlRendererLayer {
    public: 
        HtmlRendererLayer();
        ~HtmlRendererLayer();

        void onAttach([[maybe_unused]] GLFWwindow* window);
        void onUpdate();
        void onDetach();
        void onEvent(Event& event);

        static std::unique_ptr<HtmlRendererLayer> create();
    };
}


#endif //SG_BROWSER_RENDERER_LAYER_H
