#ifndef SG_BROWSER_LAYERS_H
#define SG_BROWSER_LAYERS_H

#include <string>
#include "events/Event.h"

namespace SG {
    template <typename T>
    struct Layer {
        std::string name;

        void onAttach() {
            static_cast<T*>(this)->do_onAttach();
        };
        void onDetach() {
            static_cast<T*>(this)->do_onDetach();
        };
        void onUpdate() {
            static_cast<T*>(this)->do_onUpdate();
        };
        void onEvent(Event& event) {
            static_cast<T*>(this)->do_onEvent(event);
        };
    };
}

#endif //SG_BROWSER_LAYERS_H
