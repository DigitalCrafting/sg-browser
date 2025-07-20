#include <vector>
#include "Application.h"
#include "spdlog/spdlog.h"
#include "env.h"

class Sandbox : public SG::Application {
public:
    Sandbox() {
        spdlog::info("Sandbox created!");
        spdlog::info("Resources path: {}", ResourcesPath);
        m_Gui.get()->setSearchCallback(&handler);
    }

private:
    void handleUrlSearchEvent(SG::SearchUrlAction &event) {
        spdlog::info("Searched: {}", event.getUrl());
    }

    SG::ActionHandler<SG::SearchUrlAction> handler{
        [this](SG::SearchUrlAction &e) { handleUrlSearchEvent(e); }
    };
};

int main() {
    auto app = new Sandbox();
    app->run();
    delete app;
    return 0;
}