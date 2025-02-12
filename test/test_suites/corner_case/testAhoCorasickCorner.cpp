#include "algorithm.hpp"

#include "template/multipattern_search/corner_case_template.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <set>
#include <vector>

TEST_CASE("Aho-Corasick algorithm implementation correctly handles empty input", "[corner][aho-corasick]") {
    test::multipattern::test_findAllStrings_EmptyInput(algo::findAllStringsAhoCorasick);
}

TEST_CASE("Aho-Corasick algorithm implementation correctly handles single-pattern inputs", "[corner][aho-corasick]") {
    test::multipattern::test_findAllStrings_SinglePattern(algo::findAllStringsAhoCorasick);
}

TEST_CASE("Aho-Corasick algorithm implementation correctly handles multi-pattern inputs", "[corner][aho-corasick]") {
    test::multipattern::test_findAllStrings_MultiPattern(algo::findAllStringsAhoCorasick);
}