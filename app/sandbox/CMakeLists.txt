set(EXE_SOURCES "Sandbox.cpp")
set(EXE_HEADERS "env.h")
set(EXE_INCLUDES "../.." "${CMAKE_BINARY_DIR}/configured/include")

add_executable(Sandbox ${EXE_SOURCES} ${EXE_HEADERS})
target_include_directories(Sandbox PUBLIC ${EXE_INCLUDES})
target_link_libraries(Sandbox PRIVATE
        ${LIBRARY_NAME}
        ${SCRIPT_LIB_NAME}
        ${HTML_LIB_NAME}
        imgui
        glm
)

if (ENABLE_WARNINGS)
    target_set_warnings(
            Sandbox
            ON
            OFF
    )
endif()