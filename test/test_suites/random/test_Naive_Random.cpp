#include "Naive.hpp"

#include <catch2/catch_test_macros.hpp>

#include "random_test.hpp"
#include "alphabets.hpp"


TEST_CASE("Naive stress test: bits, large text, few short patterns", "[stress][naive]") {
    test::singlepattern::test_findSingleString_RandomFill(
        algo::findStringNaive,
        util::alphabetBits,
        100'000,
        5,
        10
    );
}

TEST_CASE("Naive stress test: digits, large text, many short patterns", "[stress][naive]") {
    test::singlepattern::test_findSingleString_RandomFill(
        algo::findStringNaive,
        util::alphabetDigits,
        100'000,
        1,
        5
    );
}
