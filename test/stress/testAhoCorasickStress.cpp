#include "algorithm.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

#include "algorithm.hpp"
#include "util.hpp"
#include <iostream>

namespace {
std::string text;
std::vector<std::string> patterns;
std::vector<std::vector<size_t>> result, expected;

const std::string alphabetDigits = "0123456789";
const std::string alphabetLowercase = "abcdefghijklmnopqrstuvwxyz";
const std::string alphabetUppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

TEST_CASE("Aho-Corasick correctly handles something", "[stress][aho-corasick]") {
    // alphabet = "01";
    // SECTION("Single pattern") {
    //     text = util::generate_string_from_alphabet(10, alphabet);
    //     std::cerr << text << '\n';
    // }

}

TEST_CASE("Aho-Corasick stress test: lowercase, large text, few short patterns", "[stress][aho-corasick]") {
    const std::string &current_alphabet = alphabetLowercase;
    text = util::generate_string_from_alphabet(10000, current_alphabet);
    patterns = {};
    for (size_t i = 0; i < 10; i++) {
        patterns.emplace_back(util::generate_string_from_alphabet(10, current_alphabet));
    }
    result = algo::findAllStringsAhoCorasick(text, patterns);
    REQUIRE(util::isResultValid(text, patterns, result));
}

TEST_CASE("Aho-Corasick stress test: lowercase, large text, many short patterns", "[stress][aho-corasick]") {
    const std::string &current_alphabet = alphabetLowercase;
    text = util::generate_string_from_alphabet(10000, current_alphabet);
    patterns = {};
    for (size_t i = 0; i < 1000; i++) {
        patterns.emplace_back(util::generate_string_from_alphabet(10, current_alphabet));
    }
    result = algo::findAllStringsAhoCorasick(text, patterns);
    REQUIRE(util::isResultValid(text, patterns, result));
}
