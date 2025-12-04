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
