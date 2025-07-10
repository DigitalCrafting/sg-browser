set(LIBRARY_SOURCES "")
set(LIBRARY_HEADERS 
        "DOM.h"
        "TagContainer.h"
        "HtmlFormatter.h"
)
set(LIBRARY_INCLUDES "./")

add_library(${HTML_LIB_NAME} STATIC
        ${LIBRARY_SOURCES}
        ${LIBRARY_HEADERS}
)

add_subdirectory(parser)
add_subdirectory(types)

target_link_libraries(
        ${HTML_LIB_NAME}
        PUBLIC
        fmt::fmt
        spdlog::spdlog
)

target_include_directories(
        ${HTML_LIB_NAME} 
        PUBLIC 
        ${LIBRARY_INCLUDES}
)

if (ENABLE_WARNINGS)
    target_set_warnings(
            ${HTML_LIB_NAME}
            ON
            OFF
    )
endif()