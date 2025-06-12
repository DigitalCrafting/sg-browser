#ifndef SG_BROWSER_EVENT_H
#define SG_BROWSER_EVENT_H

#include <string>

namespace SG {
    enum EventType {

    };

    struct Event {
        std::string name;
        EventType type;
    };
}

#endif //SG_BROWSER_EVENT_H
