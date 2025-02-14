#include <benchmark.hpp>

// Global variables which define config file
const std::string pathToConfig = "./benchmark/config.json";
const json config = benchmark::loadConfig(pathToConfig);

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

void benchmark::benchmarkTimeAhoCorasik(benchmark::State& state) {
    std::vector<double> timings;
    for (auto _ : state) {
            auto start = std::chrono::high_resolution_clock::now();
            benchmark::runMultiPatternScenario(benchmark::runMultiPatternAlgo, algo::findAllStringsAhoCorasick,
                                                "AhoCorasik", config);
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

void benchmark::benchmarkTimeKnuthMorrisPratt(benchmark::State& state) {
    std::vector<double> timings;
    for (auto _ : state) {
            auto start = std::chrono::high_resolution_clock::now();
            benchmark::runSinglePatternScenario(benchmark::runSinglePatternAlgo, algo::findStringKnuthMorrisPratt,
                                                "KnuthMorrisPratt", config);
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

void benchmark::benchmarkTimeRabinCarp(benchmark::State& state) {
    std::vector<double> timings;
    for (auto _ : state) {
        auto start = std::chrono::high_resolution_clock::now();
        benchmark::runSinglePatternScenario(benchmark::runSinglePatternAlgo, algo::findStringRabinCarp,
                                            "RabinCarp", config);
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

