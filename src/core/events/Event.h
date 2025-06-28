#ifndef SG_BROWSER_EVENT_H
#define SG_BROWSER_EVENT_H

#include <string>
#include "../Core.h"

namespace SG {
    enum class EventType {
        None = 0,
        WindowClose,
        WindowResize,
        WindowFocus,
        WindowLostFocus,
        WindowMove,
        AppTick,
        AppUpdate,
        AppRender,
        KeyPress,
        KeyRelease,
        KeyType,
        MouseButtonPress,
        MouseButtonReleas,
        MouseMove,
        MouseScroll
    };
    
    enum EventCategory {
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryInput = BIT(1),
        EventCategoryKeyboard = BIT(2),
        EventCategoryMouse = BIT(3),
        EventCategoryMouseButton = BIT(4)
    };

    struct Event {
        bool handled = false;
        std::string name;
        EventType type;
        
        Event(EventType _type): type(_type) {}
    };
    
    inline std::ostream &operator<<(std::ostream &os, const Event &e) {
        return os << e.name;
    }
}

#endif //SG_BROWSER_EVENT_H
