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

TEST_CASE("Test computePowers", "[unit][rabin-carp]") {
    const uint64_t PRIME = 1000000007;
    const uint64_t BASE = 256;

    SECTION("Empty String") {
        size_t stringLength = 0;
        std::vector<uint64_t> result = precomputePowers(stringLength, PRIME, BASE);
        REQUIRE(result.empty());
    }
    
    SECTION("Single Power") {
        // verifies function correctness for strings of length 1
        size_t stringLength = 1;
        std::vector<uint64_t> result = precomputePowers(stringLength, PRIME, BASE);
        REQUIRE(result.size() == 1);
        REQUIRE(result[0] == 1);
    }
    
    SECTION("Multiple Powers") {
        size_t stringLength = 4;
        std::vector<uint64_t> result = precomputePowers(stringLength, PRIME, BASE);
        std::vector<uint64_t> expected = {1, BASE % PRIME, (BASE * BASE) % PRIME, (BASE * BASE * BASE) % PRIME};
        REQUIRE(result == expected);
    }
    
    SECTION("Large String") {
        // verifies function correctness in cases where modulo starts to apply repeatedly during power calculation
        size_t stringLength = 20;
        std::vector<uint64_t> result = precomputePowers(stringLength, PRIME, BASE);
        std::vector<uint64_t> expected(stringLength, 1);
        for (size_t i = 1; i < stringLength; ++i) {
            expected[i] = (expected[i - 1] * BASE) % PRIME;
        }
        REQUIRE(result == expected);
    }
}
