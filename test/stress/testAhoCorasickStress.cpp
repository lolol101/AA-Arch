#include "algorithm.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

#include "algorithm.hpp"
#include "util.hpp"
#include <iostream>

namespace {
std::string text;
std::set<std::string> patterns;
std::vector<std::vector<size_t>> result, expected;

const std::string alphabetDigits = "0123456789";
const std::string alphabetLowercase = "abcdefghijklmnopqrstuvwxyz";
const std::string alphabetUppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

TEST_CASE("Aho-Corasick stress test: digits, large text, few short patterns", "[stress][aho-corasick]") {
    const std::string &current_alphabet = alphabetDigits;
    text = util::generateStringFromAlphabet(100000, current_alphabet);
    patterns = {};
    for (size_t i = 0; i < 10; i++) {
        patterns.insert(util::generateStringFromAlphabet(5, current_alphabet));
    }
    result = algo::findAllStringsAhoCorasick(text, patterns);
    REQUIRE(util::isResultValid(text, patterns, result));
}

TEST_CASE("Aho-Corasick stress test: digits, large text, many short patterns", "[stress][aho-corasick]") {
    const std::string &current_alphabet = alphabetDigits;
    text = util::generateStringFromAlphabet(100000, current_alphabet);
    patterns = {};
    for (size_t i = 0; i < 10000; i++) {
        patterns.insert(util::generateStringFromAlphabet(5, current_alphabet));
    }
    result = algo::findAllStringsAhoCorasick(text, patterns);
    REQUIRE(util::isResultValid(text, patterns, result));
}
