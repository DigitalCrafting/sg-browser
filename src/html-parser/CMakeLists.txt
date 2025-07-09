set(LIBRARY_SOURCES 
        "HtmlParser.cpp"
)
set(LIBRARY_HEADERS 
        "HtmlParser.h" 
        "Html.h"
        "DOM.h"
        "HtmlTags.h"
        "TagContainer.h"
        "HtmlFormatter.h"
)
set(LIBRARY_INCLUDES "./")

add_library(${HTML_PARSER_LIB_NAME} STATIC
        ${LIBRARY_SOURCES}
        ${LIBRARY_HEADERS}
)

target_link_libraries(
        ${HTML_PARSER_LIB_NAME}
        PUBLIC
        fmt::fmt
        spdlog::spdlog
)

target_include_directories(
        ${HTML_PARSER_LIB_NAME} 
        PUBLIC 
        ${LIBRARY_INCLUDES}
)

if (ENABLE_WARNINGS)
    target_set_warnings(
            ${HTML_PARSER_LIB_NAME}
            ON
            OFF
    )
endif()