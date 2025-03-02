#include "ZFunction.hpp"

#include "corner_case.hpp"

#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

TEST_CASE("Z-function algorithm implementation correctly handles empty input", "[corner][z]") {
    test::singlepattern::test_findSingleString_EmptyInput(algo::findStringZFunction);
}

TEST_CASE("Z-function algorithm implementation correctly handles single-pattern inputs", "[corner][z]") {
    test::singlepattern::test_findSingleString_SinglePattern(algo::findStringZFunction);
}
