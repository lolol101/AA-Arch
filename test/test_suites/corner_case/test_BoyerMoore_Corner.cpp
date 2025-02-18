#include "BoyerMoore.hpp"

#include "corner_case.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Boyer-Moore algorithm implementation correctly handles empty input", "[corner][boyer-moore]") {
    test::singlepattern::test_findSingleString_EmptyInput(algo::findStringBoyerMoore);
}

TEST_CASE("Boyer-Moore algorithm implementation correctly handles single-pattern inputs", "[corner][boyer-moore]") {
    test::singlepattern::test_findSingleString_SinglePattern(algo::findStringBoyerMoore);
}