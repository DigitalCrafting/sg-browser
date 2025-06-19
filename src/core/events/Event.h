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
        WindowMoved,
        AppTick,
        AppUpdate,
        AppRender,
        KeyPressed,
        KeyReleased,
        KeyTyped,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseScrolled
    };
    
    enum EventCategory {
        None = 0,
        Application = BIT(0),
        Input = BIT(1),
        Keyboard = BIT(2),
        Mouse = BIT(3),
        MouseButton = BIT(4)
    };

    struct Event {
        std::string name;
        EventType type;
    };
}

#endif //SG_BROWSER_EVENT_H
