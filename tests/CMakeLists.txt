# Build the test executable.
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_executable(TestExTests ${TEST_SOURCES})
target_link_libraries(TestExTests PRIVATE TestEx)


# Include test frameworks for discovering tests.
include(CTest)
include(GoogleTest)
gtest_discover_tests(TestExTests)
