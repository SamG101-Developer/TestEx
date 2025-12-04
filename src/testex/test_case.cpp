export module testex.test_case;
import std;

namespace testex {
    export struct TestCase;
}


export struct testex::TestCase {
    std::string group;
    std::string name;
    std::function<void()> callback;

    const char *file;
    std::size_t line;
};
