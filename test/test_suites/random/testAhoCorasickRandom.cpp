#include "AhoCorasick.hpp"

#include <catch2/catch_test_macros.hpp>

#include "random_test.hpp"
#include "alphabets.hpp"


TEST_CASE("Aho-Corasick stress test: digits, large text, few short patterns", "[stress][aho-corasick]") {
    test::multipattern::test_findAllStrings_RandomFill(
        algo::findAllStringsAhoCorasick,
        util::alphabetDigits,
        100'000,
        10,
        5
    );
}

TEST_CASE("Aho-Corasick stress test: digits, large text, many short patterns", "[stress][aho-corasick]") {
    test::multipattern::test_findAllStrings_RandomFill(
        algo::findAllStringsAhoCorasick,
        util::alphabetDigits,
        100'000,
        10'000,
        5
    );
}
