#include "algorithm.hpp"

#include "corner_case.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("Knuth-Morris-Pratt algorithm implementation correctly handles empty input", "[corner][kmp]") {
    test::singlepattern::test_findSingleString_EmptyInput(algo::findStringKnuthMorrisPratt);
}

TEST_CASE("Knuth-Morris-Pratt algorithm implementation correctly handles single-pattern inputs", "[corner][kmp]") {
    test::singlepattern::test_findSingleString_SinglePattern(algo::findStringKnuthMorrisPratt);
}
