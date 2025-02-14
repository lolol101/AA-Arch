#include <runScenario.hpp>
#include <filesystem>

void benchmark::runSinglePatternScenario(BenchFuncType1 runSinglePatternAlgo, AlgoFuncType1 findString, const std::string& scenario, const json& config) {
    if (config.contains(scenario)) {
        for (const auto& elems : config[scenario]) {
            for (int i = 0; i < elems[0]; ++i)
                benchmark::runSinglePatternAlgo(findString, util::alphabetLowercase, elems[1], elems[2]);
        }
    } else
        std::cerr << "Invalid config.json" << "\n";
}

void benchmark::runMultiPatternScenario(BenchFuncType2 runSinglePatternAlgo, AlgoFuncType2 findAllStrings,  const std::string& scenario, const json& config) {
    if (config.contains(scenario)) {
        for (const auto& elems : config[scenario]) {
            for (int i = 0; i < elems[0]; ++i)
                benchmark::runMultiPatternAlgo(findAllStrings, util::alphabetLowercase, elems[1], elems[2], elems[3]);
        }
    } else
        std::cerr << "Ошибка: сценарий '" << scenario << "' не найден в config.json" << std::endl;
}
