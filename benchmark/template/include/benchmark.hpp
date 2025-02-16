#pragma once

#include <iostream>
#include <string>
#include <runScenario.hpp>
#include <benchAlgorithm.hpp>
#include <benchmark/benchmark.h>

using json = nlohmann::json;

namespace benchmark {
/// @brief Loads config file and exits programm in case of error
json loadConfig(const std::string& filename);

void runTemplateTimeBenchmark(benchmark::State& state, BenchFuncType1 runSinglePatternAlgo, const std::string algoName);

// Functions measure the time according to the scenario in config.json
void benchmarkTimeAhoCorasik(benchmark::State& state);
void benchmarkTimeKnuthMorrisPratt(benchmark::State& state);
void benchmarkTimeRabinCarp(benchmark::State& state);
}