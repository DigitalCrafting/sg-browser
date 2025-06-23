set(LIBRARY_SOURCES 
        "Application.cpp" 
        "layers/LayerStack.cpp" 
        "window/Window.cpp"
        "gui/ImGuiLayer.cpp"
)
set(LIBRARY_HEADERS 
        "Application.h" 
        "layers/LayerStack.h"
        "window/Window.h"
        "gui/ImGuiLayer.h"
        "KeyCodes.h"
)
set(LIBRARY_INCLUDES "./")

add_library(${LIBRARY_NAME} STATIC
        ${LIBRARY_SOURCES}
        ${LIBRARY_HEADERS}
)

target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_INCLUDES})
target_link_libraries(${LIBRARY_NAME} PUBLIC
        ${OPENGL_glu_LIBRARY}
        ${GLFW_LIBRARIES}
        ${OPENGL_gl_LIBRARY}
        glfw
        glad
        imgui
        spdlog::spdlog
)

if (ENABLE_WARNINGS)
    target_set_warnings(
            ${LIBRARY_NAME}
            ON
            OFF
    )
endif()