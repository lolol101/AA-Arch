#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <util.hpp>
#include <algorithm.hpp>
#include <fstream>
#include <iostream>

TEST_CASE("Benchmark Aho-Corasick with 100K text, 10K patterns", "[benchmark]") {
    const std::string &current_alphabet = "abcdefghijklmnopqrstuvwxyz";
    auto text = util::generateStringFromAlphabet(100000, current_alphabet);
    std::set<std::string> patterns = {};
    for (size_t i = 0; i < 10000; i++) {
        patterns.insert(util::generateStringFromAlphabet(5, current_alphabet));
    }

    std::ofstream csv_file("benchmark_results.csv", std::ios::app);
    if (csv_file.is_open()) {
        if (csv_file.tellp() == 0) {
            csv_file << "Test Name,Mean Time (ns),Iterations\n";
        }

        BENCHMARK_ADVANCED("Aho-Corasick 100K text, 10K patterns")(Catch::Benchmark::Chronometer meter) {
            meter.measure([&] {
                return algo::findAllStringsAhoCorasick(text, patterns);
            });
            csv_file << "Aho-Corasick 100K text, 10K patterns," << 123 << "," << meter.runs() << "\n";
            csv_file.close();
        };


    } else {
        std::cerr << "Ошибка при открытии файла!" << std::endl;
    }
}
