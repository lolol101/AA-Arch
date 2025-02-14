#include <benchmark.hpp>

BENCHMARK(benchmark::benchmarkTimeAhoCorasik);
BENCHMARK(benchmark::benchmarkTimeKnuthMorrisPratt);
BENCHMARK(benchmark::benchmarkTimeRabinCarp);

int main(int argc, char** argv) {
    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
}