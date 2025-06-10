set(EXE_SOURCES "Sandbox.cpp")
set(EXE_INCLUDES "../.." "${CMAKE_BINARY_DIR}/configured/include")

add_executable(Sandbox ${EXE_SOURCES})
target_include_directories(Sandbox PUBLIC ${EXE_INCLUDES})
target_link_libraries(Sandbox PRIVATE
        ${LIBRARY_NAME}
)

if (ENABLE_WARNINGS)
    target_set_warnings(
            Sandbox
            ON
            OFF
    )
endif()