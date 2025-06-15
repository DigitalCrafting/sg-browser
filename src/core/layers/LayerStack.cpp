#include "LayerStack.h"

#include <algorithm>

namespace SG {
    LayerStack::~LayerStack() {
        auto it = m_Layers.begin();
        while (it != m_Layers.end())
        {
            (*it)->onDetach((*it)->context);
            m_Layers.erase(it);
        }
    }
    
    void LayerStack::pushLayer(LayerHandle* layer) {
        m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
        m_LayerInsertIndex++;
        layer->onAttach(layer->context);
    }
    
    void LayerStack::popLayer(LayerHandle* layer) {
        auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
        if (it != m_Layers.end())
        {
            (*it)->onDetach((*it)->context);
            m_Layers.erase(it);
            m_LayerInsertIndex--;
        }
    }
    
    void LayerStack::pushOverlay(LayerHandle* overlay) {
        m_Layers.emplace_back(overlay);
        overlay->onAttach(overlay->context);
    }
    
    void LayerStack::popOverlay(LayerHandle* overlay) {
        auto it = std::find(m_Layers.begin() + m_LayerInsertIndex, m_Layers.end(), overlay);
        if (it != m_Layers.end())
        {
            overlay->onDetach(overlay->context);
            m_Layers.erase(it);
        }
    }
}