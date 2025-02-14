#pragma once

#include <util.hpp>
#include <functional>

using AlgoFuncType1 = std::function<std::vector<size_t>(const std::string &, const std::string &)>;
using AlgoFuncType2 = std::function<std::vector<std::vector<size_t>>(const std::string &, const std::set<std::string> &)>;

namespace benchmark {

void runSinglePatternAlgo(AlgoFuncType1 findString, 
                            const std::string& alphabet,
                            unsigned textSize,
                            unsigned patternSize);

void runMultiPatternAlgo(AlgoFuncType2 findAllStrings, 
                            const std::string& alphabet,
                            unsigned textSize,
                            unsigned patternSize,
                            unsigned patternCount
                            );
}