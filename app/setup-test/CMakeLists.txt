set(EXE_SOURCES "main.cc")
set(EXE_INCLUDES "../.." "${CMAKE_BINARY_DIR}/configured/include")

add_executable(0_SetupTest ${EXE_SOURCES})
target_include_directories(0_SetupTest PUBLIC ${EXE_INCLUDES})
target_link_libraries(0_SetupTest PRIVATE
        fmt::fmt
        spdlog::spdlog
        cxxopts::cxxopts
        imgui
        implot
)

if (ENABLE_WARNINGS)
    target_set_warnings(
            0_SetupTest
            ON
            OFF
    )
endif()