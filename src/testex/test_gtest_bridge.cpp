module;
#include <gtest/gtest.h>

export module testex.test_gtest_bridge;
import testex.test_registry;


namespace testex {
    export auto register_to_gtest() -> int {
        for (const auto &[group, name, callback, file, line] : TestRegistry::instance().all()) {
            auto gtest_callback = [callback=callback] {
                struct LocalTest : ::testing::Test {
                    decltype(callback) func;
                    explicit LocalTest(decltype(callback) f) : func(std::move(f)) {}
                    auto TestBody() -> void override { func(); }
                };
                return new LocalTest(callback);
            };

            ::testing::RegisterTest(
                group.c_str(), name.c_str(), nullptr, nullptr, file, line,
                std::move(gtest_callback));
        }
        return 0;
    }
}
