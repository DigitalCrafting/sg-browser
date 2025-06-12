#ifndef SG_BROWSER_LAYERSTACK_H
#define SG_BROWSER_LAYERSTACK_H

#include <vector>
#include "./Layer.h"

namespace SG {
    struct LayerStack {
    public:
        LayerStack() = default;
        ~LayerStack();

        void pushLayer(Layer *layer);
        void pushOverlay(Layer *overlay);
        void popLayer(Layer *layer);
        void popOverlay(Layer *overlay);

        std::vector<Layer *>::iterator begin() { return m_Layers.begin(); }
        std::vector<Layer *>::iterator end() { return m_Layers.end(); }
        std::vector<Layer*>::reverse_iterator rbegin() { return m_Layers.rbegin(); }
        std::vector<Layer*>::reverse_iterator rend() { return m_Layers.rend(); }


    private:
        std::vector<Layer *> m_Layers;
        unsigned int m_LayerInsertIndex = 0;
    };
}

#endif //SG_BROWSER_LAYERSTACK_H
