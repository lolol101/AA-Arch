#include "RabinCarp.hpp"

#include "corner_case.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Rabin-Carp algorithm implementation correctly handles empty input", "[corner][rabin-carp]") {
    test::singlepattern::test_findSingleString_EmptyInput(algo::findStringRabinCarp);
}

TEST_CASE("Rabin-Carp algorithm implementation correctly handles single-pattern inputs", "[corner][rabin-carp]") {
    test::singlepattern::test_findSingleString_SinglePattern(algo::findStringRabinCarp);
}
