#include "BoyerMoore.hpp"

#include <catch2/catch_test_macros.hpp>

#include "random_test.hpp"
#include "alphabets.hpp"

TEST_CASE("Boyer-Moore stress test: digits, large text, few short patterns", "[stress][boyer-moore]") {
    test::singlepattern::test_findSingleString_RandomFill(
        algo::findStringBoyerMoore,
        util::alphabetDigits,
        100'000,
        10,
        5
    );
}

TEST_CASE("Boyer-Moore stress test: digits, large text, many short patterns", "[stress][boyer-moore]") {
    test::singlepattern::test_findSingleString_RandomFill(
        algo::findStringBoyerMoore,
        util::alphabetDigits,
        100'000,
        1'000,
        5
    );
}
