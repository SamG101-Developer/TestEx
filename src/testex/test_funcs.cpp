export module testex.test_funcs;
import std;


namespace testex {
    export auto assert_true(
        const bool condition,
        std::string const &message = "")
        -> void {
        if (not condition) {
            throw std::runtime_error("Assertion failed: " + message);
        }
    }

    export auto assert_false(
        const bool condition,
        std::string const &message = "")
        -> void {
        if (condition) {
            throw std::runtime_error("Assertion failed: " + message);
        }
    }

    export auto assert_equal(
        auto const &a,
        auto const &b,
        std::string const &message = "")
        -> void {
        if (a != b) {
            throw std::runtime_error("Assertion failed: " + message);
        }
    }

    export auto assert_not_equal(
        auto const &a,
        auto const &b,
        std::string const &message = "")
        -> void {
        if (a == b) {
            throw std::runtime_error("Assertion failed: " + message);
        }
    }

    export auto fail(
        std::string const &message = "")
        -> void {
        throw std::runtime_error("Test failed: " + message);
    }

    export auto pass()
        -> void {
        // No-op for passing tests.
    }

    export template <typename E>
    auto assert_throws(
        auto const &func,
        std::string const &message = "")
        -> void {
        try {
            func();
            throw std::runtime_error("Expected exception was not thrown: " + message);
        }
        catch (E const &) {
            // Expected exception was thrown.
        }
        catch (...) {
            throw std::runtime_error("Unexpected exception type thrown: " + message);
        }
    }
}
