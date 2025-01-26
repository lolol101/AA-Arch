#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

#include "algorithm.hpp"
#include <iostream>

std::string text;
std::vector<std::string> patterns;
std::vector<std::vector<size_t>> result, expected;

TEST_CASE("Aho-Corasick algorithm implementation correctly handles empty input") {
    const auto requireResultEmpty = []() {
        REQUIRE(patterns.size() == result.size());
        for (const std::vector<size_t> occurences: result) {
            REQUIRE(occurences.empty());
        }
    };

    SECTION("Empty text") {
        text = "";
        patterns = {"a", "b"};
        result = algo::findAllStringsAhoCorasick(text, patterns);
        requireResultEmpty();
    }

    SECTION("Empty pattern list") {
        text = "abcde";
        patterns = {};
        result = algo::findAllStringsAhoCorasick(text, patterns);
        requireResultEmpty();
    }

    SECTION("Empty input") {
        text = {};
        patterns = {};
        result = algo::findAllStringsAhoCorasick(text, patterns);
        requireResultEmpty();
    }
}


TEST_CASE("Aho-Corasick algorithm implementation correctly handles single pattern") {
    SECTION("Empty pattern") {
        text = "aboba";
        patterns = {""};
        result = algo::findAllStringsAhoCorasick(text, patterns);
        expected = {{}};
        REQUIRE(result == expected);
    }

    SECTION("Single Character") {
        SECTION("Appearing single time") {
            text = "abobi";

            // at the start
            patterns = {"a"};
            result = algo::findAllStringsAhoCorasick(text, patterns);
            expected = {{0}};
            REQUIRE(result == expected);

            // in the middle
            patterns = {"o"};
            result = algo::findAllStringsAhoCorasick(text, patterns);
            expected = {{2}};
            REQUIRE(result == expected);

            // at the end
            patterns = {"i"};
            result = algo::findAllStringsAhoCorasick(text, patterns);
            expected = {{4}};
            REQUIRE(result == expected);
        }

        SECTION("Appearing multiple times") {
            text = "abaobbi";

            // apart
            patterns = {"a"};
            result = algo::findAllStringsAhoCorasick(text, patterns);
            expected = {{0, 2}};
            REQUIRE(result == expected);

            // near each other
            patterns = {"b"};
            result = algo::findAllStringsAhoCorasick(text, patterns);
            expected = {{1, 4, 5}};
            REQUIRE(result == expected);
        }

        SECTION("Not appearing") {
            text = "aboba";
            patterns = {"u"};
            result = algo::findAllStringsAhoCorasick(text, patterns);
            expected = {{}};
            REQUIRE(result == expected);
        }
    }

    SECTION("Multiple character") {
        SECTION("Unique") {
            text = "abcdefghabcdef";
            patterns = {"cde"};
            result = algo::findAllStringsAhoCorasick(text, patterns);
            expected = {{2, 10}};
            REQUIRE(result == expected);
        }
        SECTION("Repeated") {
            text = "aaabbbcccabb";
            patterns = {"bbb"};
            result = algo::findAllStringsAhoCorasick(text, patterns);
            expected = {{3}};
            REQUIRE(result == expected);

            text = "aaabbbbcccabbb";
            patterns = {"bbb"};
            result = algo::findAllStringsAhoCorasick(text, patterns);
            expected = {{3, 4, 11}};
            REQUIRE(result == expected);
        }
    }
}

TEST_CASE("Aho-Corasick algorithm implementation correctly handles multiple patterns") {
    SECTION("Non-overlapping patterns") {
        // non-repeating
        text = "abc";
        patterns = {"a", "b", "c"};
        result = algo::findAllStringsAhoCorasick(text, patterns);
        expected = {{0}, {1}, {2}};
        REQUIRE(result == expected);

        // repeating
        text = "aabbbbcbabbac";
        patterns = {"a", "b", "c"};
        result = algo::findAllStringsAhoCorasick(text, patterns);
        expected = {
            {0, 1, 8, 11}, 
            {2, 3, 4, 5, 7, 9, 10}, 
            {6, 12}
            };
        REQUIRE(result == expected);
    }

    SECTION("Partially overlapping patterns") {
        // one pattern's suffix is another pattern's prefix 
        text = "abababa";
        patterns = {"ab", "ba"};
        result = algo::findAllStringsAhoCorasick(text, patterns);
        expected = {
            {0, 2, 4},
            {1, 3, 5}
            };
        REQUIRE(result == expected);
    }

    SECTION("Fully overlapping patterns, repeated patterns") {
        // repeated single-char pattern
        // text = "aabbbbcbabbac";
        // patterns = {"a", "a", "c"};
        // result = algo::findAllStringsAhoCorasick(text, patterns);
        // expected = {
        //     {0, 1, 8, 11}, 
        //     {0, 1, 8, 11}, 
        //     {6, 12}
        //     };
        // REQUIRE(result == expected);
        // TODO: Must be dict in patterns due to Aho-Corasick requiremetns

        // repeated multichar pattern
        // text = "aaa";
        // patterns = {"aa", "aa"};
        // result = algo::findAllStringsAhoCorasick(text, patterns);
        // expected = {
        //     {0, 1},
        //     {0, 1},
        //     };
        // REQUIRE(result == expected);
        

        // text = "aboaaboa";
        // patterns = {"abo", "abo"};
        // result = algo::findAllStringsAhoCorasick(text, patterns);
        // expected = {
        //     {0, 4},
        //     {0, 4},
        //     };
        // REQUIRE(result == expected);

        // one pattern is part of another
        text = "ababababa";
        patterns = {"ab", "aba"};
        result = algo::findAllStringsAhoCorasick(text, patterns);
        expected = {
            {0, 2, 4, 6},
            {0, 2, 4, 6}
            };
        REQUIRE(result == expected);
    }
}