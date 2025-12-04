# TestEx

An extremely simple testing framework for C++.

## Usage Instructions

1. Create a `tests` subfolder from the root of your project. It should be sibling to `include` and `src`. This is the
   folder where all test files, and folders containing test files, will live.


2. Create test files with the `test_*.cpp` naming scheme. This will allow for automatic discovery of test files.
   Populate the files with tests, using the `TESTEX_TEST` macro. A group name and test name per test is required, with
   the test body following the macro.

```c++
#include <testex/macros.hpp>

import testex;
import std;


struct TestClass {
    int a;
    int b;
};


TESTEX_TEST(TestGroup1, test_1) {
    auto t = TestClass(1, 2);
    t.a *= t.b;
    testex::assert_equal(t.a, 2);
    testex::assert_equal(t.b, 2);
}


TESTEX_TEST(TestGroup1, test_2) {
    auto t = TestClass(3, 4);
    t.b += t.a;
    testex::assert_equal(t.a, 3);
    testex::assert_equal(t.b, 7);
}
```

3. Add a `main.cpp` file in the `tests` folder to run all tests. An example is provided below.

```c++
#include <testex/main.hpp>
import testex;

TESTEX_MAIN()
```

4. Finally, create a `CMakeLists.txt` file in the `tests` folder to build the tests. An example is provided below.

```cmake
# Build the test executable.
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_executable(${PROJECT_NAME}Tests ${TEST_SOURCES})

# GTest configuration.
find_package(GTest REQUIRED)
target_link_libraries(${PROJECT_NAME}Tests PRIVATE TestEx GTest::gtest)

# Include test frameworks for discovering tests.
include(CTest)
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}Tests)
```

5. In the root `CMakeLists.txt`, add the following to include the `tests` folder in the build.

```cmake
# Create the tests.
enable_testing()
add_subdirectory(tests)
```

6. Build the project using CMake. A cmake target (in this example `TestExTests`) will be created for the tests. In
   CLion, Google and CTest targets are created. Run the tests using either of these targets. I use the Google Test
   target.