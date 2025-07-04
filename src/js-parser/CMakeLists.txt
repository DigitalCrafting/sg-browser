set(LIBRARY_SOURCES "JSParser.cpp")
set(LIBRARY_HEADERS "JSParser.h")
set(LIBRARY_INCLUDES "./")

add_library(${JS_PARSER_LIB_NAME} STATIC
        ${LIBRARY_SOURCES}
        ${LIBRARY_HEADERS}
)

target_include_directories(${JS_PARSER_LIB_NAME} PUBLIC ${LIBRARY_INCLUDES})

if (ENABLE_WARNINGS)
    target_set_warnings(
            ${JS_PARSER_LIB_NAME}
            ON
            OFF
    )
endif()