#include "random_test.hpp"

#include "util.hpp"
#include <catch2/catch_test_macros.hpp>

void test::singlepattern::test_findSingleString_RandomFill(
    FuncType findString, 
    const std::string &alphabet, 
    const unsigned long textLength, const unsigned int patternCount, const unsigned long patternLength
) {
    std::string text = util::generateStringFromAlphabet(textLength, alphabet);
    
    std::set<std::string> patterns;
    for (size_t i = 0; i < patternCount; ++i) {
        patterns.insert(util::generateStringFromAlphabet(patternLength, alphabet));
    }

    for (const std::string &pattern: patterns) {
        std::vector<size_t> result = findString(text, pattern);
        REQUIRE(util::isResultValid_SinglePattern(text, pattern, result));
    }
}

void test::multipattern::test_findAllStrings_RandomFill(
    FuncType findAllStrings, 
    const std::string &alphabet, 
    const unsigned long textLength, const unsigned int patternCount, const unsigned long patternLength
) {
    std::string text = util::generateStringFromAlphabet(textLength, alphabet);
    
    std::set<std::string> patterns;
    for (size_t i = 0; i < patternCount; i++) {
        patterns.insert(util::generateStringFromAlphabet(patternLength, alphabet));
    }

    std::vector<std::vector<size_t>> result = findAllStrings(text, patterns);
    REQUIRE(util::isResultValid_MultiPattern(text, patterns, result));
}
