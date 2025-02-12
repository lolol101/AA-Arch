#include "KnuthMorrisPratt.hpp"

#include <catch2/catch_test_macros.hpp>

#include "random_test.hpp"
#include "alphabets.hpp"


TEST_CASE("Knuth-Morris-Pratt stress test: bits, large text, few short patterns", "[stress][kmp]") {
    test::singlepattern::test_findSingleString_RandomFill(
        algo::findStringKnuthMorrisPratt,
        test::util::alphabetBits,
        100'000,
        5,
        10
    );
}

TEST_CASE("Knuth-Morris-Pratt stress test: digits, large text, many short patterns", "[stress][kmp]") {
    test::singlepattern::test_findSingleString_RandomFill(
        algo::findStringKnuthMorrisPratt,
        test::util::alphabetDigits,
        100'000,
        1,
        5
    );
}
