set(LIBRARY_SOURCES "GSParser.cpp")
set(LIBRARY_HEADERS "GSParser.h")
set(LIBRARY_INCLUDES "./")

add_library(${SCRIPT_LIB_NAME} STATIC
        ${LIBRARY_SOURCES}
        ${LIBRARY_HEADERS}
)

target_include_directories(${SCRIPT_LIB_NAME} PUBLIC ${LIBRARY_INCLUDES})

if (ENABLE_WARNINGS)
    target_set_warnings(
            ${SCRIPT_LIB_NAME}
            ON
            OFF
    )
endif()