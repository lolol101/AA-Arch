#include <benchmark.hpp>

BENCHMARK(benchmark::benchmarkTimeAhoCorasik);
BENCHMARK(benchmark::benchmarkTimeKnuthMorrisPratt);
BENCHMARK(benchmark::benchmarkTimeRabinCarp);
BENCHMARK(benchmark::benchmarkMemoryBoyerMoore);
BENCHMARK(benchmark::benchmarkMemoryAhoCorasik);
BENCHMARK(benchmark::benchmarkMemoryKnuthMorrisPratt);
BENCHMARK(benchmark::benchmarkMemoryBoyerMoore);
BENCHMARK(benchmark::benchmarkMemoryRabinCarp);

int main(int argc, char** argv) {
    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
}