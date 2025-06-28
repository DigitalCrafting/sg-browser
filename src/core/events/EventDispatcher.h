#ifndef SG_BROWSER_EVENT_DISPATCHER_H
#define SG_BROWSER_EVENT_DISPATCHER_H

#include "Event.h"

namespace SG {
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
}


#endif //SG_BROWSER_EVENT_DISPATCHER_H
