set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/config/cmake/")

include(AddGitSubmodule)
include(FetchContent)
include(Docs)

if(ENABLE_WARNINGS)
    include(Warnings)
endif()

add_subdirectory(configured)