set(LIBRARY_SOURCES "EventHorizon.cpp")
set(LIBRARY_HEADERS "EventHorizon.h")
set(LIBRARY_INCLUDES "./")

add_library(${HTML_PARSER_LIB_NAME} STATIC
        ${LIBRARY_SOURCES}
        ${LIBRARY_HEADERS}
)

target_include_directories(${HTML_PARSER_LIB_NAME} PUBLIC ${LIBRARY_INCLUDES})

if (ENABLE_WARNINGS)
    target_set_warnings(
            ${HTML_PARSER_LIB_NAME}
            ON
            OFF
    )
endif()