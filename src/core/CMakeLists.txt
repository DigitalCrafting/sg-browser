set(LIBRARY_SOURCES "Application.cpp" "layers/LayerStack.cpp")
set(LIBRARY_HEADERS "Application.h" "entry-point/SGBrowser.h")
set(LIBRARY_INCLUDES "./" "entry-point")

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