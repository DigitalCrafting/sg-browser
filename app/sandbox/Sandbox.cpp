#include <vector>
#include "Application.h"
#include "layers/LayerWrapper.h"
#include "layers/LayerStack.h"
#include "events/BrowserEvents.h"
#include "spdlog/spdlog.h"


struct FirstLayer {
    void onAttach() {
        spdlog::info("First layer onAttach!");
    }

    void onDetach() {
        spdlog::info("First layer onDetach!");
    }

    void onUpdate() {
        spdlog::info("First layer onUpdate!");
    }

    void onEvent(SG::Event &event) {
        spdlog::info("First layer onEvent!");
    }
};


class Sandbox : public SG::Application {
public:
    Sandbox() {
        spdlog::info("Sandbox created!");

        SG::LayerWrapper<FirstLayer> firstLayer;

        SG::LayerStack layerStack;

        layerStack.pushLayer(firstLayer.getHandle());
        m_Gui.get()->setCallback(std::bind(&Sandbox::handleEvent, this, std::placeholders::_1));
    }

private:
    void handleEvent(SG::Event &event) {
        SG::EventDispatcher dispatcher(event);

        dispatcher.dispatch<SG::SearchUrlEvent>(std::bind(&Sandbox::handleUrlSearchEvent, this, std::placeholders::_1));
    }
    
    bool handleUrlSearchEvent(SG::SearchUrlEvent &event) {
        spdlog::info("Searched: {}", event.getUrl());
        return true;
    }
};

int main(int argc, char **args) {
    auto app = new Sandbox();
    app->run();
    delete app;
    return 0;
}