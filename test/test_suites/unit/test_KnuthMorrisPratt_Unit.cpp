#include "KnuthMorrisPratt.hpp"

#include <catch2/catch_test_macros.hpp>

using namespace algo::util::kmp;

TEST_CASE("Test calculateLPSArray", "[unit][kmp]") {
    SECTION("Empty string") {
        std::string pattern = "";
        std::vector<size_t> lps;
        calculateLPSArray(pattern, lps);
        REQUIRE(lps.empty());
    }
    
    SECTION("Single-char string") {
        std::string pattern = "A";
        std::vector<size_t> lps;
        calculateLPSArray(pattern, lps);
        REQUIRE(lps.size() == 1);
        REQUIRE(lps[0] == 0);
    }
    
    SECTION("String of repeating character") {
        std::string pattern = "AAAA";
        std::vector<size_t> lps;
        calculateLPSArray(pattern, lps);
        REQUIRE(lps.size() == 4);
        REQUIRE(lps == std::vector<size_t>{0, 1, 2, 3});
    }
    
    SECTION("String of unique characters") {
        std::string pattern = "ABCDE";
        std::vector<size_t> lps;
        calculateLPSArray(pattern, lps);
        REQUIRE(lps.size() == 5);
        REQUIRE(lps == std::vector<size_t>{0, 0, 0, 0, 0});
    }
    
    SECTION("String of overlapping patterns") {
        std::string pattern = "ABABABA";
        std::vector<size_t> lps;
        calculateLPSArray(pattern, lps);
        REQUIRE(lps.size() == 7);
        REQUIRE(lps == std::vector<size_t>{0, 0, 1, 2, 3, 4, 5});
    }
        
    SECTION("Overlapping patterns with interruption") {
        std::string pattern = "AAACAAAA";
        std::vector<size_t> lps;
        calculateLPSArray(pattern, lps);
        REQUIRE(lps.size() == 8);
        REQUIRE(lps == std::vector<size_t>{0, 1, 2, 0, 1, 2, 3, 3});
    }
}
