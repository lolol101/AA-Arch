#pragma once

#include <iostream>
#include <string>
#include <runScenario.hpp>
#include <benchAlgorithm.hpp>
#include <benchmark/benchmark.h>

using json = nlohmann::json;

namespace benchmark {
// Loads config file and exits program in case of error.
json loadConfig(const std::string& filename);

// Measures Aho-Corasick algorithm execution time according to the scenario in config.json, saving results to state.
void benchmarkTimeAhoCorasik(benchmark::State& state);

/// Measures Knuth-Morris-Pratt algorithm execution time according to the scenario in config.json, saving results to state.
void benchmarkTimeKnuthMorrisPratt(benchmark::State& state);

// Measures Rabin-Carp algorithm execution time according to the scenario in config.json, saving results to state.
void benchmarkTimeRabinCarp(benchmark::State& state);
}