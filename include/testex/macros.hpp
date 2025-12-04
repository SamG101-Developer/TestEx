#pragma once


/**
 * Define a test case with the given group and name. The body of the test is provided in braces after the macro.
 * @param group The group name of the test case.
 * @param name The name of the test case.
 */
#define TESTEX_TEST(given_group, given_name)                                                      \
    auto test_func_##given_group##_##given_name() -> void;                                    \
    struct Registrator_##given_group##_##given_name {                                         \
        Registrator_##given_group##_##given_name() {                                          \
            testex::TestRegistry::instance().add(                                             \
                testex::TestCase{                                                             \
                    .group = #given_group,                                                    \
                    .name = #given_name,                                                      \
                    .callback = &test_func_##given_group##_##given_name,                      \
                    .file = __FILE__,                                                         \
                    .line = __LINE__                                                          \
                }                                                                             \
            );                                                                                \
        }                                                                                     \
    };                                                                                        \
    static Registrator_##given_group##_##given_name registrator_##given_group##_##given_name; \
    auto test_func_##given_group##_##given_name() -> void


#define TESTEX_MAIN()                   \
    auto main() -> int {                \
        return testex::run_all_tests(); \
    }
