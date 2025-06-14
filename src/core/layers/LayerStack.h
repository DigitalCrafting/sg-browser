#ifndef SG_BROWSER_LAYERSTACK_H
#define SG_BROWSER_LAYERSTACK_H

#include <vector>
#include "./Layer.h"

namespace SG {
    struct LayerStack {
    public:
        LayerStack() = default;
        ~LayerStack();

        void pushLayer(void* layer);
        void pushOverlay(void* overlay);
        void popLayer(void* layer);
        void popOverlay(void* overlay);

        std::vector<LayerInterface*>::iterator begin() { return m_Layers.begin(); }
        std::vector<LayerInterface*>::iterator end() { return m_Layers.end(); }
        std::vector<LayerInterface*>::reverse_iterator rbegin() { return m_Layers.rbegin(); }
        std::vector<LayerInterface*>::reverse_iterator rend() { return m_Layers.rend(); }


    private:
        std::vector<LayerInterface *> m_Layers;
        unsigned int m_LayerInsertIndex = 0;
    };
}

#endif //SG_BROWSER_LAYERSTACK_H
