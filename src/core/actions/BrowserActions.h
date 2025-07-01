#ifndef SG_BROWSER_BROWSER_EVENTS_H
#define SG_BROWSER_BROWSER_EVENTS_H

#include "Actions.h"
#include <string_view>

namespace SG {
    class SearchUrlAction : public Action {
    public:
        explicit SearchUrlAction(char* _url): Action(ActionType::UrlSearch), url(_url) {}

        static const char* getName() {
            return ENUM_NAME(ActionType::UrlSearch);
        }

        ActionType getActionType() {
            return getStaticType();
        }
        
        std::string_view getUrl() {
            return url;
        }

        static ActionType getStaticType() {
            return ActionType::UrlSearch;
        }
        
    private:
        std::string_view url;
    };
}

#endif //SG_BROWSER_BROWSER_EVENTS_H
