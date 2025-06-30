#ifndef SG_BROWSER_MOUSEEVENT_H
#define SG_BROWSER_MOUSEEVENT_H

#include "Events.h"

namespace SG {
    class MouseMoveEvent : public Event {
    public:
        MouseMoveEvent(): Event(EventType::MouseMove) {}
        
        const char* getName() {
            return ENUM_NAME(EventType::MouseMove);
        }
        
        EventType getEventType() {
            return getStaticType();
        }
        
        static EventType getStaticType() {
            return EventType::MouseMove;
        }
    };
    
    class MouseScrollEvent : public Event {
    public:
        MouseScrollEvent(): Event(EventType::MouseScroll) {}
        
        const char* getName() {
            return ENUM_NAME(EventType::MouseScroll);
        }

        EventType getEventType() {
            return getStaticType();
        }
        
        static EventType getStaticType() {
            return EventType::MouseScroll;
        }
    };
}


#endif //SG_BROWSER_MOUSEEVENT_H
