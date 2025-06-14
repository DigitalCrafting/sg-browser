#ifndef SG_BROWSER_LAYERS_H
#define SG_BROWSER_LAYERS_H

#include <string>
#include "events/Event.h"

namespace SG {
    struct LayerInterface {
        void (*onAttach)(void*);
        void (*onDetach)(void*);
        void (*onUpdate)(void*);
        void (*onEvent)(void*, Event& event);
        void* context;
    };

    template<typename T>
    struct LayerHandle {
        static void onAttachHandle(void* ctx) {
            static_cast<T*>(ctx)->onAttach();
        }
        static void onDetachHandle(void* ctx) {
            static_cast<T*>(ctx)->onDetach();
        }
        static void onUpdateHandle(void* ctx) {
            static_cast<T*>(ctx)->onUpdate();
        }
        static void onEventHandle(void* ctx, Event& event) {
            static_cast<T*>(ctx)->onEvent(event);
        }    
    };
}

#endif //SG_BROWSER_LAYERS_H
