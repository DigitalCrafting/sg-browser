#include "HtmlRendererLayer.h"
#include "spdlog/spdlog.h"

namespace SG {
    HtmlRendererLayer::HtmlRendererLayer() {
        
    }
    
    HtmlRendererLayer::~HtmlRendererLayer() {
        
    }
    
    void HtmlRendererLayer::onAttach([[maybe_unused]] GLFWwindow *window) {
    
    }
    
    void HtmlRendererLayer::onUpdate() {
        
    }
    
    void HtmlRendererLayer::onDetach() {
        
    }
    
    void HtmlRendererLayer::onEvent(SG::Event &event) {
        spdlog::info("HtmlRendererLayer::onEvent {}", event.name);
    }
    
    std::unique_ptr<HtmlRendererLayer> HtmlRendererLayer::create() {
        return std::make_unique<HtmlRendererLayer>();
    }
}