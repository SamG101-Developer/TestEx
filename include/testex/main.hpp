#pragma once
#include <gtest/gtest.h>


namespace {
    struct FilePathPrintingListener final : ::testing::EmptyTestEventListener {
        auto OnTestStart(const testing::TestInfo &test_info) -> void override {
            std::cout << "Starting test: " << test_info.test_case_name()
                << "." << test_info.name()
                << " (" << test_info.file()
                << ":" << test_info.line()
                << ")" << std::endl;
        }
    };
}


/**
 * Define an entry point for running all registered test cases using Google Test. Just include this file
 * (testex/main.hpp), and importing testex is enough, to use this macro.
 */
#define TESTEX_MAIN()                                                                               \
    auto main(int argc, char **argv) -> int {                                                       \
        testex::register_to_gtest();                                                                \
        ::testing::InitGoogleTest(&argc, argv);                                                     \
        ::testing::TestEventListeners &listeners = ::testing::UnitTest::GetInstance()->listeners(); \
        listeners.Append(new FilePathPrintingListener());                                           \
        return RUN_ALL_TESTS();                                                                     \
    }
