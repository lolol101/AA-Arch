#include "ZFunction.hpp"

#include <catch2/catch_test_macros.hpp>

#include "random_test.hpp"
#include "alphabets.hpp"


TEST_CASE("Z-function stress test: bits, large text, few short patterns", "[stress][z]") {
    test::singlepattern::test_findSingleString_RandomFill(
        algo::findStringZFunction,
        util::alphabetBits,
        100'000,
        5,
        10
    );
}

TEST_CASE("Z-function stress test: digits, large text, many short patterns", "[stress][z]") {
    test::singlepattern::test_findSingleString_RandomFill(
        algo::findStringZFunction,
        util::alphabetDigits,
        100'000,
        1,
        5
    );
}
