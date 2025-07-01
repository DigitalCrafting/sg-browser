#ifndef SG_BROWSER_EVENT_H
#define SG_BROWSER_EVENT_H

#include <string>
#include "../Core.h"

namespace SG {
    enum class EventType {
        None = 0,
        // Window Events
        WindowClose,
        WindowResize,
        WindowFocus,
        WindowLostFocus,
        WindowMove,
        AppTick,
        AppUpdate,
        AppRender,
        
        // Generic Actions
        KeyPress,
        KeyRelease,
        KeyType,
        MouseButtonPress,
        MouseButtonRelease,
        MouseMove,
        MouseScroll,
    };
    
    enum EventCategory {
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryInput = BIT(1),
        EventCategoryKeyboard = BIT(2),
        EventCategoryMouse = BIT(3),
        EventCategoryMouseButton = BIT(4),
        EventCategoryBrowser = BIT(5),
    };

    struct Event {
        bool handled = false;
        std::string name;
        EventType type;
        
        Event(EventType _type): type(_type) {}
    };

    class EventDispatcher {
    public:
        explicit EventDispatcher(Event& _event): event(_event) {}

        template<typename T, typename F>
        bool dispatch(const F& func) {
            if (event.type == T::getStaticType()) {
                event.handled = func(static_cast<T&>(event));
                return true;
            }
            return false;
        }

    private:
        Event& event;
    };
    
    inline std::ostream &operator<<(std::ostream &os, const Event &e) {
        return os << e.name;
    }
}

#endif //SG_BROWSER_EVENT_H
