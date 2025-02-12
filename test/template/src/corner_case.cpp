#include "corner_case.hpp"

#include <catch2/catch_test_macros.hpp>
#include "util.hpp"

#include <set>
#include <vector>
#include <string>
#include <functional>

namespace test::singlepattern {

    using FuncType = std::function<std::vector<size_t>(const std::string &, const std::string &)>;

    /// @brief Runs corner case tests for single-pattern search function in which not all required input is present.
    void test_findSingleString_EmptyInput(FuncType findSingleString) {
        std::string text;
        std::string pattern;
        std::vector<size_t> result, expected;
    
        SECTION("Handles case when no text is provided") {
            // Verify behaviour when only text is missing
            text = "";
            pattern = "a";
            result = findSingleString(text, pattern);
            REQUIRE(result.empty());
        }
    
        SECTION("Handles empty pattern") {
            // Verify behaviour when only pattern is missing
            text = "abcde";
            pattern = "";
            result = findSingleString(text, pattern);
            REQUIRE(result.empty());
        }
    
        SECTION("Handles fully empty input") {
            // Verify behaviour when both text and pattern are missing
            text = {};
            pattern = {};
            result = findSingleString(text, pattern);
            REQUIRE(result.empty());
        }
    }
    
    /// @brief Runs corner case tests for a multipattern search function in case where only one pattern is provided.
    void test_findSingleString_SinglePattern(FuncType findSingleString) {
        std::string text;
        std::string pattern;
        std::vector<size_t> result, expected;
    
        SECTION("Handles single-character pattern") {
            SECTION("Single occurrence of the character") {
                // Test cases where the character appears once in the text
                text = "abobi";
                pattern = "a";
                result = findSingleString(text, pattern);
                expected = {0};
                REQUIRE(result == expected);
    
                pattern = "o";
                result = findSingleString(text, pattern);
                expected = {2};
                REQUIRE(result == expected);
    
                pattern = "i";
                result = findSingleString(text, pattern);
                expected = {4};
                REQUIRE(result == expected);
            }
    
            SECTION("Multiple occurrences of the character") {
                // Test cases where the character appears multiple times
                text = "abaobbi";
                pattern = "a";
                result = findSingleString(text, pattern);
                expected = {0, 2};
                REQUIRE(result == expected);
    
                pattern = "b";
                result = findSingleString(text, pattern);
                expected = {1, 4, 5};
                REQUIRE(result == expected);
            }
    
            SECTION("Character not present in the text") {
                // Verify behavior when the character does not appear in the text
                text = "aboba";
                pattern = "u";
                result = findSingleString(text, pattern);
                REQUIRE(result.empty());
            }
        }
    
        SECTION("Handles multi-character pattern") {
            SECTION("Unique pattern in the text") {
                // Test cases where the pattern appears uniquely
                text = "abcdefghabcef";
                pattern = {"cde"};
                result = findSingleString(text, pattern);
                expected = {2};
                REQUIRE(result == expected);
            }
    
            SECTION("Repeated pattern in the text") { // TODO: choose better patterns
                // Test cases where the pattern appears multiple times
                text = "aaabbbcccabb";
                pattern = {"bbb"};
                result = findSingleString(text, pattern);
                expected = {3};
                REQUIRE(result == expected);
    
                text = "aaabbbbcccabbb";
                pattern = {"bbb"};
                result = findSingleString(text, pattern);
                expected = {3, 4, 11};
                REQUIRE(result == expected);

                text = "abobabebabuubbaabooob";
                pattern = "ab";
                result = findSingleString(text, pattern);
                expected = {0, 4, 8, 15};
                REQUIRE(result == expected);

                text = "1111111";
                pattern = "111111";
                result = findSingleString(text, pattern);
                expected = {0, 1};
                REQUIRE(result == expected);

                text = "0100011111001110101111111101010001111110100000001000000111010110010001111100001000010011111010110011110";
                pattern = "10001";
                result = findSingleString(text, pattern);
                expected = {1, 29, 65};
                REQUIRE(result == expected);
            }
        }
    }
    
}

namespace test::multipattern {

using FuncType = std::function<std::vector<std::vector<size_t>>(const std::string &, const std::set<std::string> &)>;

/// @brief Runs corner case tests for multipattern search function in which not all required input is present.
void test_findAllStrings_EmptyInput(FuncType findAllStrings) {
    std::string text;
    std::set<std::string> patterns;
    std::vector<std::vector<size_t>> result, expected;

    const auto requireResultEmpty = [&]() {
        REQUIRE(patterns.size() == result.size());
        for (const std::vector<size_t> occurences: result) {
            REQUIRE(occurences.empty());
        }
    };

    SECTION("Handles case when no text is provided") {
        // Verify behaviour when only text is missing
        text = "";
        patterns = {"a", "b"};
        result = findAllStrings(text, patterns);
        requireResultEmpty();
    }

    SECTION("Handles empty pattern list") {
        // Verify behaviour when only patterns are missing
        text = "abcde";
        patterns = {};
        result = findAllStrings(text, patterns);
        requireResultEmpty();
    }

    SECTION("Handles fully empty input") {
        // Verify behaviour when both text and patterns are missing
        text = {};
        patterns = {};
        result = findAllStrings(text, patterns);
        requireResultEmpty();
    }
}


/// @brief Runs corner case tests for a multipattern search function in case where only one pattern is provided.
void test_findAllStrings_SinglePattern(FuncType findAllStrings) {
    std::string text;
    std::set<std::string> patterns;
    std::vector<std::vector<size_t>> result, expected;

    SECTION("Handles empty pattern") {
        // Verify behavior when the pattern is an empty string
        text = "aboba";
        patterns = {""};
        result = findAllStrings(text, patterns);
        expected = {{}};
        REQUIRE(result == expected);
    }

    SECTION("Handles single-character patterns") {
        SECTION("Single occurrence of the character") {
            // Test cases where the character appears once in the text
            text = "abobi";
            patterns = {"a"};
            result = findAllStrings(text, patterns);
            expected = {{0}};
            REQUIRE(result == expected);

            patterns = {"o"};
            result = findAllStrings(text, patterns);
            expected = {{2}};
            REQUIRE(result == expected);

            patterns = {"i"};
            result = findAllStrings(text, patterns);
            expected = {{4}};
            REQUIRE(result == expected);
        }

        SECTION("Multiple occurrences of the character") {
            // Test cases where the character appears multiple times
            text = "abaobbi";
            patterns = {"a"};
            result = findAllStrings(text, patterns);
            expected = {{0, 2}};
            REQUIRE(result == expected);

            patterns = {"b"};
            result = findAllStrings(text, patterns);
            expected = {{1, 4, 5}};
            REQUIRE(result == expected);
        }

        SECTION("Character not present in the text") {
            // Verify behavior when the character does not appear in the text
            text = "aboba";
            patterns = {"u"};
            result = findAllStrings(text, patterns);
            expected = {{}};
            REQUIRE(result == expected);
        }
    }

    SECTION("Handles multi-character patterns") {
        SECTION("Unique pattern in the text") {
            // Test cases where the pattern appears uniquely
            text = "abcdefghabcdef";
            patterns = {"cde"};
            result = findAllStrings(text, patterns);
            expected = {{2, 10}};
            REQUIRE(result == expected);
        }

        SECTION("Repeated pattern in the text") {
            // Test cases where the pattern appears multiple times
            text = "aaabbbcccabb";
            patterns = {"bbb"};
            result = findAllStrings(text, patterns);
            expected = {{3}};
            REQUIRE(result == expected);

            text = "aaabbbbcccabbb";
            patterns = {"bbb"};
            result = findAllStrings(text, patterns);
            expected = {{3, 4, 11}};
            REQUIRE(result == expected);
        }
    }
}

/// @brief Runs corner case tests for a multipattern search function in case where only one pattern is provided.
void test_findAllStrings_MultiPattern(FuncType findAllStrings) {
    std::string text;
    std::set<std::string> patterns;
    std::vector<std::vector<size_t>> result, expected;

    SECTION("Handles non-overlapping patterns") {
        SECTION("Non-repeating patterns") {
            // Verify behavior when patterns do not overlap and appear only once in the text
            text = "abc";
            patterns = {"a", "b", "c"};
            result = findAllStrings(text, patterns);
            expected = {{0}, {1}, {2}};
            REQUIRE(result == expected);
        }

        SECTION("Repeating patterns") {
            // Verify behavior when patterns do not overlap but appear multiple times in the text
            text = "aabbbbcbabbac";
            patterns = {"a", "b", "c"};
            result = findAllStrings(text, patterns);
            expected = {
                {0, 1, 8, 11},  // Positions of 'a'
                {2, 3, 4, 5, 7, 9, 10},  // Positions of 'b'
                {6, 12}  // Positions of 'c'
            };
            REQUIRE(result == expected);
        }
    }

    SECTION("Handles partially overlapping patterns") {
        SECTION("One pattern's suffix is another pattern's prefix") {
            // Verify behavior when one pattern's suffix matches another pattern's prefix
            text = "abababa";
            patterns = {"ab", "ba"};
            result = findAllStrings(text, patterns);
            expected = {
                {0, 2, 4},  // Positions of 'ab'
                {1, 3, 5}   // Positions of 'ba'
            };
            REQUIRE(result == expected);
        }

        SECTION("One pattern is a prefix of another") {
            // Verify behavior when one pattern is a prefix of another
            text = "ababababa";
            patterns = {"ab", "aba"};
            result = findAllStrings(text, patterns);
            expected = {
                {0, 2, 4, 6},  // Positions of 'ab'
                {0, 2, 4, 6}   // Positions of 'aba' (overlaps with 'ab')
            };
            REQUIRE(result == expected);
        }

        SECTION("One pattern is a suffix of another") {
            // Verify behavior when one pattern is a suffix of another
            text = "ababababa";
            patterns = {"aba", "ba"};
            result = findAllStrings(text, patterns);
            REQUIRE(util::isResultValid_MultiPattern(text, patterns, result)); // Use utility function to validate results
        }
    }
}

}
