#include "MouseEvent.h"

namespace SG {
    EventType MouseEvent::getStaticType() {
        return EventType::MouseMoved;
    }
}