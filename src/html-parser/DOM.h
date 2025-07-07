#ifndef SG_BROWSER_DOM_H
#define SG_BROWSER_DOM_H

#include "Html.h"

namespace SG {
    struct DOMNode {
        Html::TagType getType() {
            return type;
        }
        
    private:
        Html::TagType type;
        void* tagPtr;
    };
    
    struct DOMTree {
    private:
        DOMNode* root;
    };
}

#endif //SG_BROWSER_DOM_H
