#ifndef SG_BROWSER_ACTIONS_H
#define SG_BROWSER_ACTIONS_H

#include <string>
#include <functional>

namespace SG {
    enum class ActionType {
        None = 0,
        UrlSearch
    };
    
    struct Action {
        std::string name;
        ActionType type;
        
        Action(ActionType _type): type(_type) {}
    };
    
    template<class T>
    class ActionHandler {
    public:
        using HandlerFunction = std::function<void(T&)>;
        
        explicit ActionHandler(HandlerFunction _handler): handler(std::move(_handler)) {}
        
        void handleAction(T& action) {
            if (handler) {
                handler(action);
            }
        } 
        
    private:
        HandlerFunction handler;
    };
}

#endif //SG_BROWSER_ACTIONS_H
