#ifndef SG_BROWSER_DOM_H
#define SG_BROWSER_DOM_H

#include "src/html/types/Html.h"
#include <vector>
#include <memory>

namespace SG {
    struct DOMNode {
        Html::TagType getType() {
            return type;
        }
        
    private:
        Html::TagType type;
        std::vector<void*> tagPtrs;
        std::vector<std::unique_ptr<DOMNode>> children;
    };
    
    struct DOMTree {
    private:
        DOMNode* root;
    };
}

#endif //SG_BROWSER_DOM_H
