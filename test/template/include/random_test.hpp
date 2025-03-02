#pragma once

#include <string>
#include <set>
#include <vector>
#include <functional>

namespace test::singlepattern {
using FuncType = std::function<std::vector<size_t>(const std::string &, const std::string &)>;

void test_findSingleString_RandomFill(
    FuncType findString, 
    const std::string &alphabet,
    const unsigned long textLength,
    const unsigned int patternCount,
    const unsigned long patternLength
);
}

namespace test::multipattern {

using FuncType = std::function<std::vector<std::vector<size_t>>(const std::string &, const std::set<std::string> &)>;

void test_findAllStrings_RandomFill(
    FuncType findAllStrings, 
    const std::string &alphabet,
    const unsigned long textLength,
    const unsigned int patternCount,
    const unsigned long patternLength
);
}