#include <benchmark.hpp>

// Global variables which define config file
const std::string pathToConfig = "./benchmark/config.json";
const json config = benchmark::loadConfig(pathToConfig);


// Global counter of allocated data
std::atomic<unsigned long long> allocatedMemory(0);
std::atomic<unsigned long long> numOfAllocs(0);

// Override of "new"
void* operator new(size_t size) {
    allocatedMemory += size;
    ++numOfAllocs;
    return std::malloc(size);
}

// Override of "delete"
void operator delete(void* ptr, size_t size) noexcept {
    allocatedMemory -= size;
    --numOfAllocs;
    std::free(ptr);
}

/// @brief Loads config file and exits programm in case of error
json benchmark::loadConfig(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Ошибка: не удалось открыть " << filename << "\n";
        exit(1);
    }
    json config;
    file >> config;
    return config;
}

namespace benchmark {
template <typename FuncType1, typename FuncType2, typename FuncType3>
void runTemplateTimeBenchmark(benchmark::State& state, FuncType1 runScenario, FuncType2 runAlgo, FuncType3 algoFunc, const std::string algoName) {
    std::vector<double> timings;
    for (auto _ : state) {
        auto start = std::chrono::high_resolution_clock::now();
        runScenario(runAlgo, algoFunc, algoName, config);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        timings.push_back(duration.count() * 1e6);
    }

    if (!timings.empty()) {
        std::sort(timings.begin(), timings.end());
        double sum = std::accumulate(timings.begin(), timings.end(), 0.0);
        double avg = sum / timings.size();
        double median = timings[timings.size() / 2];
        double min_time = timings.front();
        double max_time = timings.back();

        state.counters["avg_time_us"] = avg;
        state.counters["median_time_us"] = median;
        state.counters["min_time_us"] = min_time;
        state.counters["max_time_us"] = max_time;
    }
}

template <typename FuncType1, typename FuncType2, typename FuncType3>
void runTemplateMemoryBenchmark(benchmark::State& state, FuncType1 runScenario, FuncType2 runAlgo, FuncType3 algoFunc, const std::string algoName) {
    numOfAllocs = 0;
    allocatedMemory = 0;
    std::vector<double> memAllocs;
    std::vector<double> memNumAllocs;
    for (auto _ : state) {
        runScenario(runAlgo, algoFunc, algoName, config);
        memAllocs.push_back(allocatedMemory);
        memNumAllocs.push_back(numOfAllocs);
    }

    if (!memAllocs.empty()) {
        std::sort(memAllocs.begin(), memAllocs.end());
        std::sort(memNumAllocs.begin(), memNumAllocs.end());
        std::pair<double, double> sum = {std::accumulate(memAllocs.begin(), memAllocs.end(), 0.0), std::accumulate(memNumAllocs.begin(), memNumAllocs.end(), 0.0)};
        std::pair<double, double> avg = {sum.first / memAllocs.size(), sum.second / memNumAllocs.size()};
        std::pair<double, double> median = {memAllocs[memAllocs.size() / 2], memNumAllocs[memNumAllocs.size() / 2]};
        std::pair<double, double> min_mem = {memAllocs.front(), memNumAllocs.front()};
        std::pair<double, double> max_mem = {memAllocs.back(), memNumAllocs.back()};

        state.counters["avg_memory_bytes"] = avg.first;
        state.counters["median_memory_bytes"] = median.first;
        state.counters["min_memory_bytes"] = min_mem.first;
        state.counters["max_memory_bytes"] = max_mem.first;
        state.counters["avg_num_allocs"] = avg.second;
        state.counters["median_num_allocs"] = median.second;
        state.counters["min_num_allocs"] = min_mem.second;
        state.counters["max_num_allocs"] = max_mem.second;
    }
}
}

void benchmark::benchmarkTimeAhoCorasik(benchmark::State& state) {
    runTemplateTimeBenchmark(state, benchmark::runMultiPatternScenario, benchmark::runMultiPatternAlgo, algo::findAllStringsAhoCorasick, "AhoCorasik");
}

void benchmark::benchmarkTimeKnuthMorrisPratt(benchmark::State& state) {
    runTemplateTimeBenchmark(state, benchmark::runSinglePatternScenario, benchmark::runSinglePatternAlgo, algo::findStringKnuthMorrisPratt, "RabinCarp");
}

void benchmark::benchmarkTimeRabinCarp(benchmark::State& state) {
    runTemplateTimeBenchmark(state, benchmark::runSinglePatternScenario, benchmark::runSinglePatternAlgo, algo::findStringRabinCarp, "RabinCarp");
}

void benchmark::benchmarkMemoryAhoCorasik(benchmark::State& state) {
    runTemplateMemoryBenchmark(state, benchmark::runMultiPatternScenario, benchmark::runMultiPatternAlgo, algo::findAllStringsAhoCorasick, "AhoCorasik");
}

void benchmark::benchmarkMemoryKnuthMorrisPratt(benchmark::State& state) {
    runTemplateMemoryBenchmark(state, benchmark::runSinglePatternScenario, benchmark::runSinglePatternAlgo, algo::findStringKnuthMorrisPratt, "RabinCarp");
}

void benchmark::benchmarkMemoryRabinCarp(benchmark::State& state) {
    runTemplateMemoryBenchmark(state, benchmark::runSinglePatternScenario, benchmark::runSinglePatternAlgo, algo::findStringRabinCarp, "RabinCarp");
}

void benchmark::benchmarkMemoryBoyerMoore(benchmark::State& state) {
    runTemplateMemoryBenchmark(state, benchmark::runSinglePatternScenario, benchmark::runSinglePatternAlgo, algo::findStringRabinCarp, "RabinCarp");
}
