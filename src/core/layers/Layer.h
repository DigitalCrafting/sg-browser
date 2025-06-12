#ifndef SG_BROWSER_LAYERS_H
#define SG_BROWSER_LAYERS_H

#include <string>
#include "events/Event.h"

namespace SG {
    struct Layer {
        std::string name;

        void onAttach() {};
        void onDetach() {};
        void onUpdate() {};
        void onEvent(Event& event) {};
    };
}

#endif //SG_BROWSER_LAYERS_H
