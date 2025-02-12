#pragma once

#include <nlohmann/json.hpp>
#include <algorithm.hpp>
#include <iostream>
#include <fstream> 
#include <vector>
#include <util.hpp>

using AlgoFuncType1 = std::function<std::vector<size_t>(const std::string&, const std::string &)>;
using AlgoFuncType2 = std::function<std::vector<std::vector<size_t>>(const std::string&, const std::set<std::string> &)>;

using BenchFuncType1 = std::function<void(AlgoFuncType1, const std::string&, unsigned, unsigned)>;
using BenchFuncType2 = std::function<void(AlgoFuncType2, const std::string&, unsigned, unsigned)>;
using json = nlohmann::json;

namespace benchmark {
/// @brief Loads json from "filename"
json loadConfig(const std::string& filename);

/// @brief Runs benchmark with scenario from config.json for single pattern algorithms
void runSinglePatternScenario(BenchFuncType1 benchSinglePatternAlgo, AlgoFuncType1 findString);

/// @brief Runs benchmark with scenario from config.json for multi pattern algorithms
void runMultiPatternScenario(BenchFuncType2 benchMultiPatternAlgo, AlgoFuncType2 findAllStrings);
}