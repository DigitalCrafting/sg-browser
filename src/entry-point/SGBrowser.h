#ifndef SG_BROWSER_ENTRYPOINT_H
#define SG_BROWSER_ENTRYPOINT_H

#include "../core/Application.h"

extern SG::Application* SG::CreateApplication();

int main() {
    auto app = SG::CreateApplication();
    app->run();
    delete app;
    return 0;
}

#endif //SG_BROWSER_ENTRYPOINT_H
