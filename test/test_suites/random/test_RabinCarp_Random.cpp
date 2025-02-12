#include "RabinCarp.hpp"

#include <catch2/catch_test_macros.hpp>

#include "random_test.hpp"
#include "alphabets.hpp"


TEST_CASE("Rabin-Carp stress test: digits, large text, few short patterns", "[stress][rabin-carp]") {
    test::singlepattern::test_findSingleString_RandomFill(
        algo::findStringRabinCarp,
        test::util::alphabetDigits,
        100'000,
        10,
        5
    );
}

TEST_CASE("Rabin-Carp stress test: digits, large text, many short patterns", "[stress][rabin-carp]") {
    test::singlepattern::test_findSingleString_RandomFill(
        algo::findStringRabinCarp,
        test::util::alphabetDigits,
        100'000,
        1'000,
        5
    );
}
