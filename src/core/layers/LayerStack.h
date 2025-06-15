#ifndef SG_BROWSER_LAYERSTACK_H
#define SG_BROWSER_LAYERSTACK_H

#include <vector>
#include "./LayerHandle.h"

namespace SG {
    struct LayerStack {
    public:
        LayerStack() = default;
        ~LayerStack();

        void pushLayer(LayerHandle* layer);
        void pushOverlay(LayerHandle* overlay);
        void popLayer(LayerHandle* layer);
        void popOverlay(LayerHandle* overlay);

        std::vector<LayerHandle*>::iterator begin() { return m_Layers.begin(); }
        std::vector<LayerHandle*>::iterator end() { return m_Layers.end(); }
        std::vector<LayerHandle*>::reverse_iterator rbegin() { return m_Layers.rbegin(); }
        std::vector<LayerHandle*>::reverse_iterator rend() { return m_Layers.rend(); }


    private:
        std::vector<LayerHandle *> m_Layers;
        unsigned int m_LayerInsertIndex = 0;
    };
}

#endif //SG_BROWSER_LAYERSTACK_H
