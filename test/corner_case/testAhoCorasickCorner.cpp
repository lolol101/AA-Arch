#include "algorithm.hpp"

#include "corner_case_template.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <set>
#include <vector>

TEST_CASE("Aho-Corasick algorithm implementation correctly handles empty input", "[corner][aho-corasick]") {
    test_CornerCase_EmptyInput(algo::findAllStringsAhoCorasick);
}

TEST_CASE("Aho-Corasick algorithm implementation correctly handles single pattern", "[corner][aho-corasick]") {
    test_CornerCase_SinglePattern(algo::findAllStringsAhoCorasick);
}

TEST_CASE("Aho-Corasick algorithm implementation correctly handles multiple patterns", "[corner][aho-corasick]") {
    test_CornerCase_MultiPattern(algo::findAllStringsAhoCorasick);
}