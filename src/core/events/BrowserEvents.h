#ifndef SG_BROWSER_BROWSER_EVENTS_H
#define SG_BROWSER_BROWSER_EVENTS_H

#include "Event.h"
#include <string_view>

namespace SG {
    class SearchUrlEvent : public Event {
    public:
        SearchUrlEvent(char* _url): url(_url), Event(EventType::UrlSearch) {}

        const char* getName() {
            return ENUM_NAME(EventType::UrlSearch);
        }

        EventType getEventType() {
            return getStaticType();
        }
        
        std::string_view getUrl() {
            return url;
        }

        static EventType getStaticType() {
            return EventType::UrlSearch;
        }
        
    private:
        std::string_view url;
    };
}

#endif //SG_BROWSER_BROWSER_EVENTS_H
