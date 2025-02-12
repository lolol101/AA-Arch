#include <runScenario.hpp>
#include <filesystem>

// Функция для загрузки конфигурации из файла
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

void benchmark::runSinglePatternScenario(BenchFuncType1 benchSinglePatternAlgo, AlgoFuncType1 findString) {
    json config = loadConfig("./benchmark/config.json");
    std::string scenario = "KnuthMorrisPrattScenario";
    std::vector<double> durations;

    if (config.contains(scenario)) {
        std::cout << "Benchmark start: " << scenario << "\n";
        for (const auto& elems : config[scenario]) {
            auto start = std::chrono::high_resolution_clock::now();
            for (int i = 0; i < elems[0]; ++i) {
                benchSinglePatternAlgo(findString, "abcdefgh", elems[1], elems[2]);
            }
            auto end = std::chrono::high_resolution_clock::now();
            double duration = std::chrono::duration<double>(end - start).count();
            durations.push_back(duration);
        };
    
        std::sort(durations.begin(), durations.end());
        double sum = std::accumulate(durations.begin(), durations.end(), 0.0);
        double mean = sum / durations.size();
        double median = durations[durations.size() / 2];
        double min_duration = durations.front();
        double max_duration = durations.back();
    
        double variance = 0.0;
        for (const auto& duration : durations) {
            variance += std::pow(duration - mean, 2);
        }
        double stddev = std::sqrt(variance / durations.size());
    
        json result = {
            {"benchmark_name", scenario},
            {"mean", mean},
            {"median", median},
            {"min", min_duration},
            {"max", max_duration},
            {"stddev", stddev},
            {"durations", durations}
        };
    
        std::ofstream out("./benchmark/results/" + scenario + ".json");
        out << result.dump(4);
        out.close();
        std::cout << "Benchmark finished" << scenario << "\n";

    } else {
        std::cerr << "Invalid config.json" << "\n";
    }
}

void benchmark::runMultiPatternScenario(BenchFuncType2 benchSinglePatternAlgo, AlgoFuncType2 findAllStrings) {
    // json config = loadConfig("config.json");
    // std::string scenario = "KnuthMorrisPrattScenario";

    // if (config[scenario].contains(scenario)) {
    //     std::cout << "Benchmark start: " << scenario << "\n";
    //     for (const auto& elems : config[scenario][scenario]) {
    //         for (int i = 0; i < elems[0]; ++i)
    //             benchMultiPatternAlgo(findString, "abcdefgh", elems[1], elems[2], elems[3]);
    //     }
    //     std::cout << "Benchmark finished" << scenario << "\n";
    // } else {
    //     std::cerr << "Ошибка: сценарий '" << scenario << "' не найден в config.json" << std::endl;
    //     return 1;
    // }
}
