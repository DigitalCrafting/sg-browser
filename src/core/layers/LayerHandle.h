#ifndef SG_BROWSER_LAYERS_H
#define SG_BROWSER_LAYERS_H

#include <string>
#include "events/Events.h"

namespace SG {
    struct LayerHandle {
        void (*onAttach)(void*);
        void (*onDetach)(void*);
        void (*onUpdate)(void*);
        void (*onEvent)(void*, Event& event);
        void* context;
    };
}

#endif //SG_BROWSER_LAYERS_H
