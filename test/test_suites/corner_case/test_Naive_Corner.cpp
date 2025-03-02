#include "Naive.hpp"

#include "corner_case.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Naive algorithm implementation correctly handles empty input", "[corner][naive]") {
test::singlepattern::test_findSingleString_EmptyInput(algo::findStringNaive);
}

TEST_CASE("Naive algorithm implementation correctly handles single-pattern inputs", "[corner][naive]") {
test::singlepattern::test_findSingleString_SinglePattern(algo::findStringNaive);
}
