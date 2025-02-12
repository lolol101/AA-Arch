#include <catch2/catch_test_macros.hpp>

#include <runScenario.hpp>
#include <benchAlgorithm.hpp>
#include <algorithm.hpp>

TEST_CASE("Benchmark findStringAlgorithm", "[benchmark]") {
    benchmark::runSinglePatternScenario(benchmark::singlepattern::benchSinglePatternAlgo, algo::findStringKnuthMorrisPratt);
}