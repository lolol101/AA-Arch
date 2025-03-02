#include "LCS.hpp"

#include "corner_case.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("LCS algorithm implementation correctly handles empty input", "[corner][lcs]") {
test::singlepattern::test_findSingleString_EmptyInput(algo::findStringLCS);
}

TEST_CASE("LCS algorithm implementation correctly handles single-pattern inputs", "[corner][lcs]") {
test::singlepattern::test_findSingleString_SinglePattern(algo::findStringLCS);
}
