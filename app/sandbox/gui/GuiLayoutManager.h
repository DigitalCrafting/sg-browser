#ifndef SG_BROWSER_GUI_LAYOUT_MANAGER_H
#define SG_BROWSER_GUI_LAYOUT_MANAGER_H

namespace LayoutManager {
    struct Dimensions {
        float width, height;
        bool isVisible;

        Dimensions(
                float _width,
                float _height,
                bool _isVisible = true
        ) :
                width(_width),
                height(_height),
                isVisible(_isVisible) {

        }
    };

    struct Layout {
        Dimensions topBar;
        Dimensions devTools;
        Dimensions pageRenderArea;

        Layout(Dimensions _topBar, 
               Dimensions _devTools, 
               Dimensions _pageRenderArea) : 
               topBar(_topBar),
               devTools(_devTools),
               pageRenderArea(_pageRenderArea) {}
    };

    Layout getLayout(float width, float height, bool devToolsVisible = false) {
        auto topBar = Dimensions(width, 40.0f);
        auto devTools = Dimensions(height - 40.0f, width * 0.3f, devToolsVisible);
        auto pageRenderArea = Dimensions(height - 40.0f, devToolsVisible ? width - devTools.width : width);
        
        return Layout{topBar, devTools, pageRenderArea};
    }
};

#endif //SG_BROWSER_GUI_LAYOUT_MANAGER_H
