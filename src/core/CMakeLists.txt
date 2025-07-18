set(LIBRARY_SOURCES 
        "Application.cpp" 
        "window/Window.cpp"
        "gui/ImGuiLayer.cpp"
        "renderer/HtmlRendererLayer.cpp"
)
set(LIBRARY_HEADERS 
        "Application.h" 
        "window/Window.h"
        "gui/ImGuiLayer.h"
        "KeyCodes.h"
        "renderer/HtmlRendererLayer.h"
)
set(LIBRARY_INCLUDES "./")

add_library(${LIBRARY_NAME} STATIC
        ${LIBRARY_SOURCES}
        ${LIBRARY_HEADERS}
)

add_subdirectory(events)
add_subdirectory(actions)
add_subdirectory(layers)

target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_INCLUDES})
target_link_libraries(${LIBRARY_NAME} PUBLIC
        ${OPENGL_glu_LIBRARY}
        ${GLFW_LIBRARIES}
        ${OPENGL_gl_LIBRARY}
        glfw
        glad
        glm
        imgui
        spdlog::spdlog
        ${OPENGL_RENDERER_LIB_NAME}
)

if (ENABLE_WARNINGS)
    target_set_warnings(
            ${LIBRARY_NAME}
            ON
            OFF
    )
endif()