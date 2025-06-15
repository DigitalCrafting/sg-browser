#ifndef SG_BROWSER_LAYERWRAPPER_H
#define SG_BROWSER_LAYERWRAPPER_H

#include "LayerHandle.h"

namespace SG {
    template<typename T>
    struct LayerHandleTemplate {
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
    
    template<typename T>
    struct LayerWrapper {
        T* instance;
        SG::LayerHandle handle;
        
        LayerWrapper() {
            instance = new T();
            handle = {
                .onAttach = SG::LayerHandleTemplate<T>::onAttachHandle,
                .onDetach = SG::LayerHandleTemplate<T>::onDetachHandle,
                .onUpdate = SG::LayerHandleTemplate<T>::onUpdateHandle,
                .onEvent = SG::LayerHandleTemplate<T>::onEventHandle,
                .context = instance
            };
        }
        
        ~LayerWrapper() {
            delete instance;
        }
        
        SG::LayerHandle* getHandle() {return &handle;};
    };
}

#endif //SG_BROWSER_LAYERWRAPPER_H
