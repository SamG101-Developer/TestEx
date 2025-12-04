#pragma once


/**
 * Define a test case with the given group and name. The body of the test is provided in braces after the macro.
 * @param group The group name of the test case.
 * @param name The name of the test case.
 */
#define TESTEX_TEST(GROUP, NAME)                                                                          \
    static void GROUP##_##NAME##_impl();                                                                  \
    static bool GROUP##_##NAME##_registered =                                                             \
        testex::TestRegistry::instance().add({#GROUP, #NAME, GROUP##_##NAME##_impl, __FILE__, __LINE__}); \
    static void GROUP##_##NAME##_impl()
