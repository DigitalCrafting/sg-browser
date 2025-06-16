include(Catch)

set(TEST_MAIN "unit_tests")
set(TEST_SOURCES "LayersTest.cpp")
set(TEST_INCLUDES "./")

set(EXE_INCLUDES "../.." "${CMAKE_BINARY_DIR}/configured/include")

add_executable(${TEST_MAIN} ${TEST_SOURCES})
target_include_directories(${TEST_MAIN} PUBLIC ${TEST_INCLUDES} "${CMAKE_BINARY_DIR}/configured/include")
target_link_libraries(${TEST_MAIN} PUBLIC ${LIBRARY_NAME} Catch2::Catch2WithMain)

catch_discover_tests(${TEST_MAIN})