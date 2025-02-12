#pragma once

#include <util.hpp>
#include <functional>
#include <catch2/benchmark/catch_benchmark.hpp>

using AlgoFuncType1 = std::function<std::vector<size_t>(const std::string &, const std::string &)>;
using AlgoFuncType2 = std::function<std::vector<std::vector<size_t>>(const std::string &, const std::set<std::string> &)>;

namespace benchmark::singlepattern {

void benchSinglePatternAlgo(AlgoFuncType1 findString, 
                            const std::string& alphabet,
                            unsigned textSize,
                            unsigned patternSize);
}

namespace benchmark::multipattern {

void benchMultiPatternAlgo(AlgoFuncType2 findAllStrings, 
                            const std::string& alphabet,
                            unsigned textSize,
                            unsigned patternSize,
                            unsigned patternCount
                            );
}