#include "AhoCorasick.hpp"

#include "corner_case.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Aho-Corasick algorithm implementation correctly handles empty input", "[corner][aho-corasick]") {
    test::multipattern::test_findAllStrings_EmptyInput(algo::findAllStringsAhoCorasick);
}

TEST_CASE("Aho-Corasick algorithm implementation correctly handles single-pattern inputs", "[corner][aho-corasick]") {
    test::multipattern::test_findAllStrings_SinglePattern(algo::findAllStringsAhoCorasick);
}

TEST_CASE("Aho-Corasick algorithm implementation correctly handles multi-pattern inputs", "[corner][aho-corasick]") {
    test::multipattern::test_findAllStrings_MultiPattern(algo::findAllStringsAhoCorasick);
}