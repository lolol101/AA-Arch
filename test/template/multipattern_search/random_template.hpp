#pragma once

#include "util.hpp"

#include <catch2/catch_test_macros.hpp>

#include <string>
#include <set>
#include <vector>


template<typename Func>
void test_findAllStrings_RandomFill(
    Func findAllStrings, 
    const std::string &alphabet,
    const unsigned long textLength,
    const unsigned int patternCount,
    const unsigned long patternLength
) {
    std::string text = util::generateStringFromAlphabet(100000, alphabet);
    
    std::set<std::string> patterns;
    for (size_t i = 0; i < 10; i++) {
        patterns.insert(util::generateStringFromAlphabet(5, alphabet));
    }

    std::vector<std::vector<size_t>> result = algo::findAllStringsAhoCorasick(text, patterns);
    REQUIRE(util::isResultValid(text, patterns, result));
}