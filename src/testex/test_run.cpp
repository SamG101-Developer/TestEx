export module testex.test_run;
import testex.test_registry;
import testex.test_case;
import std;

#define CALC_TIME\
    auto end_time = std::chrono::high_resolution_clock::now();\
    auto test_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start).count();\
    group_time += test_time;


namespace testex {
    export auto run_all_tests()
        -> std::int32_t {
        auto &registry = TestRegistry::instance();
        auto &tests = registry.all();

        // Simple grouping based on test groups.
        auto groups = std::map<std::string, std::vector<TestCase*>>{};
        for (auto &test : tests) {
            groups[test.group].push_back(&test);
        }

        // Counters and totals.
        const auto total_tests = tests.size();
        const auto total_groups = groups.size();
        auto passed_tests = 0;
        auto failed_tests = 0;
        auto total_time = 0;

        std::print("[==========] Running {} tests from {} test suites.\n", total_tests, total_groups);
        std::print("[----------] Global test environment set-up.\n");

        // Run each group.
        for (auto const &[group_name, group_tests] : groups) {
            std::print("[----------] {} tests from {}\n", group_tests.size(), group_name);
            auto group_time = 0;
            for (auto const &test : group_tests) {
                std::print("[ RUN      ] {}.{}\n", test->group, test->name);
                auto start = std::chrono::high_resolution_clock::now();

                try {
                    test->callback();
                    CALC_TIME;
                    std::print("[       OK ] {}.{} ({} ms)\n", test->group, test->name, test_time);
                    passed_tests++;
                }
                catch (const std::exception &) {
                    CALC_TIME;
                    std::print("[  FAILED  ] {}.{} ({} ms)\n", test->group, test->name, test_time);
                    failed_tests++;
                }
                catch (...) {
                    CALC_TIME;
                    std::print("[  FAILED  ] {}.{} ({} ms)\n", test->group, test->name, test_time);
                    failed_tests++;
                }
            }
            total_time += group_time;
            std::print("[----------] {} tests from group {} ({} ms total)\n", group_tests.size(), group_name, group_time);
        }

        // Print the summary.
        std::print("[==========] {} tests from {} test suites ran. ({} ms total)\n", total_tests, total_groups, /* TODO: total time */ 0);
        std::print("[  PASSED  ] {} tests.\n", passed_tests);
        std::print("[  FAILED  ] {} tests.\n", failed_tests);

        return failed_tests > 0 ? 1 : 0;
    }
}
