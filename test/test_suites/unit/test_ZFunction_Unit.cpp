#include "ZFunction.hpp"

#include <catch2/catch_test_macros.hpp>
#include <unordered_map>
#include <vector>

using namespace algo::util::z;

TEST_CASE("Test findSeparator", "[z][unit]") {
    SECTION("First ASCII character is not contained") {
        std::string pattern = "abcd";
        std::string text = "some text with English letters";
        char sep = findSeparator(text, pattern);
        REQUIRE(sep == 1);
    }

    SECTION("The first few ASCII characters in the text or in the pattern") {
        std::vector <char> patternVector{'\4', 'a', 'b', '\1', '\2', '\3', '\0'};
        std::vector <char> textVector{'e', '\1', '\5', '\7', '\6', 'z', '8', '\0'};
        std::string pattern(patternVector.data());
        std::string text(textVector.data());
        char sep = findSeparator(text, pattern);
        REQUIRE(sep == 8);
    }
}

TEST_CASE("Test calculateZFunction", "[z][unit]") {
    SECTION("All symbols are different") {
        std::string text = "abcdefg";
        std::vector <int> expected(7, 0);
        expected[0] = 7;
        std::vector <int> z = calculateZFunction(text);
        REQUIRE(z == expected);
    }

    SECTION("Empty stromg") {
        std::vector <int> z = calculateZFunction("");
        REQUIRE(z == std::vector <int>{});
    }

    SECTION("abacaba") {
        std::vector <int> z = calculateZFunction("abacaba");
        std::vector <int> expected{7, 0, 1, 0, 3, 0, 1};
        REQUIRE(z == expected);
    }
}

TEST_CASE("Test findStringZFunction", "[z][unit]") {
    SECTION("Pattern = one character") {
        std::string text = "abcdefagabaa";
        std::string pattern = "a";
        std::vector <std::size_t> expected{0, 6, 8, 10, 11};
        std::vector <std::size_t> result = algo::findStringZFunction(text, pattern);
        REQUIRE(result == expected);
    }

    SECTION("There are no occurrences") {
        std::string text = "abcdefagabaa";
        std::string pattern = "abacaba";
        std::vector <std::size_t> expected{};
        std::vector <std::size_t> result = algo::findStringZFunction(text, pattern);
        REQUIRE(result == expected);
    }

    SECTION("Empty pattern and text") {
        std::string text = "";
        std::string pattern = "";
        std::vector <std::size_t> expected{};
        std::vector <std::size_t> result = algo::findStringZFunction(text, pattern);
        REQUIRE(result == expected);
    }

    SECTION("Short pattern") {
        std::string text = "dabacabadedabasome";
        std::string pattern = "aba";
        std::vector <std::size_t> expected{1, 5, 11};
        std::vector <std::size_t> result = algo::findStringZFunction(text, pattern);
        REQUIRE(result == expected);
    }
}

