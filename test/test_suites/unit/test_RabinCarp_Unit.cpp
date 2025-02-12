#include "RabinCarp.hpp"

#include <catch2/catch_test_macros.hpp>
#include <iostream>

using namespace algo::util::rabincarp;

TEST_CASE("Test computeHash", "[unit][rabin-carp]") {
    const uint64_t PRIME = 1000000007;
    const uint64_t BASE = 256;

    SECTION("Empty string hash is 0") {
        REQUIRE(computeHash("", PRIME, BASE) == 0);
    }

    SECTION("Short equal substrings have equal hashes") {
        std::string text = "a____a";
        std::string_view textView(text);
        REQUIRE(computeHash(text.substr(0, 1), PRIME, BASE) == computeHash(text.substr(5, 1), PRIME, BASE));
    }

    SECTION("Long equal substrings have equal hashes") {
        std::string text = "abobaabeba____abobaabeba";
        std::string_view textView(text);
        REQUIRE(computeHash(text.substr(0, 10), PRIME, BASE) == computeHash(text.substr(14, 10), PRIME, BASE));
    }
}
