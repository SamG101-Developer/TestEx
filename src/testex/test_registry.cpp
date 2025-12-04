export module testex.test_registry;
import testex.test_case;
import std;

namespace testex {
    export struct TestRegistry;
}


export struct testex::TestRegistry {
private:
    std::vector<TestCase> m_tests;

public:
    static auto instance()
        -> TestRegistry& {
        static TestRegistry registry;
        return registry;
    }

    auto all()
        -> std::vector<TestCase>& {
        return m_tests;
    }

    auto add(
        TestCase &&test_case)
        -> bool {
        m_tests.push_back(std::move(test_case));
        return true;
    }
};
