#include <benchmark.hpp>

BENCHMARK(benchmark::benchmarkTimeAhoCorasik);
BENCHMARK(benchmark::benchmarkTimeKnuthMorrisPratt);
BENCHMARK(benchmark::benchmarkTimeRabinCarp);
BENCHMARK(benchmark::benchmarkTimeBoyerMoore);
BENCHMARK(benchmark::benchmarkTimeLCS);
BENCHMARK(benchmark::benchmarkTimeZFunction);
BENCHMARK(benchmark::benchmarkTimeNaive);
BENCHMARK(benchmark::benchmarkMemoryAhoCorasik);
BENCHMARK(benchmark::benchmarkMemoryKnuthMorrisPratt);
BENCHMARK(benchmark::benchmarkMemoryBoyerMoore);
BENCHMARK(benchmark::benchmarkMemoryRabinCarp);
BENCHMARK(benchmark::benchmarkMemoryLCS);
BENCHMARK(benchmark::benchmarkMemoryZFunction);
BENCHMARK(benchmark::benchmarkMemoryNaive);

int main(int argc, char** argv) {
    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();
}