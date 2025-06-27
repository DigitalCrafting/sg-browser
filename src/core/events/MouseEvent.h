#ifndef SG_BROWSER_MOUSEEVENT_H
#define SG_BROWSER_MOUSEEVENT_H

#include "Event.h"

namespace SG {
    class MouseEvent : public Event {
        static EventType getStaticType(); 
    };
}


#endif //SG_BROWSER_MOUSEEVENT_H
