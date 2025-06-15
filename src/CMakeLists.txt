set(LIBRARY_SOURCES "core/Application.cpp" "core/layers/LayerStack.cpp")
set(LIBRARY_HEADERS "core/Application.h" "entry-point/SGBrowser.h")
set(LIBRARY_INCLUDES "./core" "./entry-point")

add_library(${LIBRARY_NAME} STATIC
        ${LIBRARY_SOURCES}
        ${LIBRARY_HEADERS}
)

target_include_directories(${LIBRARY_NAME} PUBLIC ${LIBRARY_INCLUDES})

if (ENABLE_WARNINGS)
    target_set_warnings(
            ${LIBRARY_NAME}
            ON
            OFF
    )
endif()