#include "BoyerMoore.hpp"

#include <catch2/catch_test_macros.hpp>
#include <unordered_map>
#include <vector>

using namespace algo::util::boyer_moore;

TEST_CASE("Test buildBadCharTable", "[boyer-moore][unit]") {
    SECTION("Correctly builds table for a pattern with unique characters") {
        std::string pattern = "abcd";
        auto table = buildBadCharTable(pattern);

        REQUIRE(table.size() == 4);
        REQUIRE(table['a'] == 0);
        REQUIRE(table['b'] == 1);
        REQUIRE(table['c'] == 2);
        REQUIRE(table['d'] == 3);
    }

    SECTION("Correctly builds table for a pattern with repeating characters") {
        std::string pattern = "abacab";
        auto table = buildBadCharTable(pattern);

        REQUIRE(table.size() == 3); // 3 unique symbols in string: a, b, c
        REQUIRE(table['a'] == 4);
        REQUIRE(table['b'] == 5);
        REQUIRE(table['c'] == 3);
    }

    SECTION("Handles empty pattern") {
        std::string pattern = "";
        auto table = buildBadCharTable(pattern);

        REQUIRE(table.empty());
    }
}

TEST_CASE("Test buildGoodSuffixTable", "[boyer-moore][unit]") {
    SECTION("Correctly builds table for a pattern with no repeating suffixes") {
        std::string pattern = "abcde";
        auto table = buildGoodSuffixTable(pattern);

        REQUIRE(table.size() == pattern.size());
        REQUIRE(table[0] == 5); // no suffix match, shift by full pattern length
        REQUIRE(table[1] == 5);
        REQUIRE(table[2] == 5);
        REQUIRE(table[3] == 5);
        REQUIRE(table[4] == 1);
    }

    SECTION("Correctly builds table for a pattern with repeating suffixes") {
        std::string pattern = "abacab";
        auto table = buildGoodSuffixTable(pattern);

        REQUIRE(table.size() == pattern.size());
        REQUIRE(table[0] == 4);
        REQUIRE(table[1] == 4);
        REQUIRE(table[2] == 4);
        REQUIRE(table[3] == 4);
        REQUIRE(table[4] == 6);
        REQUIRE(table[5] == 1);
    }

    SECTION("Handles empty pattern") {
        std::string pattern = "";
        auto table = buildGoodSuffixTable(pattern);

        REQUIRE(table.empty());
    }

    SECTION("Handles single-character pattern") {
        std::string pattern = "a";
        auto table = buildGoodSuffixTable(pattern);

        REQUIRE(table.size() == 1);
        REQUIRE(table[0] == 1); // No suffix match, shift by full pattern length
    }
}