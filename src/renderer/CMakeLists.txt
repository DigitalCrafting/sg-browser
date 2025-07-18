set(LIBRARY_SOURCES "Camera.cpp")
set(LIBRARY_HEADERS "Camera.h")
set(LIBRARY_INCLUDES "./")

add_library(${OPENGL_RENDERER_LIB_NAME} STATIC
        ${LIBRARY_SOURCES}
        ${LIBRARY_HEADERS}
)

target_link_libraries(
        ${OPENGL_RENDERER_LIB_NAME}
        PUBLIC
        ${OPENGL_glu_LIBRARY}
        ${GLFW_LIBRARIES}
        ${OPENGL_gl_LIBRARY}
        glfw
        glad
        glm::glm
        spdlog::spdlog
)

target_include_directories(
        ${OPENGL_RENDERER_LIB_NAME}
        PUBLIC
        ${LIBRARY_INCLUDES}
)

if (ENABLE_WARNINGS)
    target_set_warnings(
            ${OPENGL_RENDERER_LIB_NAME}
            ON
            OFF
    )
endif()