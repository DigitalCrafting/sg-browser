#ifndef SG_BROWSER_MOUSEEVENT_H
#define SG_BROWSER_MOUSEEVENT_H

#include "Event.h"

namespace SG {
    class MouseMoveEvent : public Event {
        static EventType getStaticType() {
            return EventType::MouseMove;
        }
    };
    
    class MouseScrollEvent : public Event {
        static EventType getStaticType() {
            return EventType::MouseScroll;
        }
    };
}


#endif //SG_BROWSER_MOUSEEVENT_H
