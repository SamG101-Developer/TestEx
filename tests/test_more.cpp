#include <testex/macros.hpp>
import testex;
import std;


TESTEX_TEST(TestGroup2, test_1) {
    testex::assert_true(true);
}


TESTEX_TEST(TestGroup2, test_2) {
    testex::assert_equal(42, 40 + 2);
}


TESTEX_TEST(TestGroup2, test_3) {
    testex::assert_false(false);
}


TESTEX_TEST(TestGroup2, test_4) {
    auto throwable = [] { throw std::runtime_error("This is a test exception"); };
    testex::assert_throws<std::runtime_error>(throwable);
}


TESTEX_TEST(TestGroup2, test_5) {
    testex::assert_true(true);
}
