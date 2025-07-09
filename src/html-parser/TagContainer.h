#ifndef SG_BROWSER_TAG_CONTAINER_H
#define SG_BROWSER_TAG_CONTAINER_H

#include "Html.h"
#include "HtmlTags.h"
#include "HtmlFormatter.h"

#include "spdlog/spdlog.h"

#include <vector>

namespace SG {
    namespace Html {
        struct TagContainer {
            ~TagContainer() {
                for (size_t i = 0; i < tags.size(); ++i) {
                    switch (tags[i].getType()) {
                        case TagType::DivSection:
                            delete static_cast<DivTag*>(tags[i].getPtr());
                            break;
                        case TagType::SpanSection:
                            delete static_cast<SpanTag*>(tags[i].getPtr());
                            break;
                        default:
                            auto tag = tags[i].getType();
                            spdlog::error("You forgot to implement free for tag {}", SG::Html::TagToString(tag));  
                    }
                }
            }
            
        private:
            std::vector<TypedTag> tags;
        };
    }
}

#endif //SG_BROWSER_TAG_CONTAINER_H
