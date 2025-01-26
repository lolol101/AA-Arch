#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

#include "algorithm.hpp"
#include <iostream>

TEST_CASE( "Aho-Corasick algorithm implementation works as intended") {
    std::string text;
    std::vector<std::string> patterns;
    std::vector<std::vector<size_t>> result;

    const auto resultEquals = [&result](const std::initializer_list<std::vector<size_t>>& ilist) {
        return result == std::vector<std::vector<size_t>>(ilist);
    };

    SECTION("1. Empty input") {
        const auto requireResultEmpty = [&text, &patterns, &result]() {
            REQUIRE(patterns.size() == result.size());
            for (const std::vector<size_t> occurences: result) {
                REQUIRE(occurences.empty());
            }
        };

        SECTION("1.1 Empty text") {
            text = "";
            patterns = {"a", "b"};
            result = algo::findAllStringsAhoCorasick(text, patterns);
            requireResultEmpty();
        }

        SECTION("1.2 Empty pattern list") {
            text = "abcde";
            patterns = {};
            result = algo::findAllStringsAhoCorasick(text, patterns);
            requireResultEmpty();
        }

        SECTION("1.3 Empty input") {
            text = {};
            patterns = {};
            result = algo::findAllStringsAhoCorasick(text, patterns);
            requireResultEmpty();
        }
    }

    SECTION("2. Single pattern") {
        SECTION("2.1 Empty pattern") {
            text = "aboba";
            patterns = {""};
            result = algo::findAllStringsAhoCorasick(text, patterns);
            REQUIRE(resultEquals({{}}));
        }

        SECTION("2.2 Single Character") {
            SECTION("2.2.1 Appearing single time") {
                text = "abobi";

                // at the start
                patterns = {"a"};
                result = algo::findAllStringsAhoCorasick(text, patterns);
                REQUIRE(resultEquals({{0}}));

                // in the middle
                patterns = {"o"};
                result = algo::findAllStringsAhoCorasick(text, patterns);
                REQUIRE(resultEquals({{2}}));

                // at the end
                patterns = {"i"};
                result = algo::findAllStringsAhoCorasick(text, patterns);
                REQUIRE(resultEquals({{4}}));
            }

            SECTION("2.2.2 Appearing multiple times") {
                text = "abaobbi";

                // apart
                patterns = {"a"};
                result = algo::findAllStringsAhoCorasick(text, patterns);
                REQUIRE(resultEquals({{0, 2}}));

                // near each other
                patterns = {"b"};
                result = algo::findAllStringsAhoCorasick(text, patterns);
                REQUIRE(resultEquals({{1, 4, 5}}));
            }

            SECTION("Not appearing") {
                text = "aboba";
                patterns = {"u"};
                result = algo::findAllStringsAhoCorasick(text, patterns);
                REQUIRE(resultEquals({{}}));
            }
        }

        SECTION("2.3 Multiple character") {
            SECTION("2.3.1 Unique") {
                text = "abcdefghabcdef";
                patterns = {"cde"};
                result = algo::findAllStringsAhoCorasick(text, patterns);
                REQUIRE(resultEquals({{2, 8}}));
            }
            SECTION("2.3.2 Repeated") {
                text = "aaabbbcccabb";
                patterns = {"bbb"};
                result = algo::findAllStringsAhoCorasick(text, patterns);
                REQUIRE(resultEquals({{2, 8}}));

                text = "aaabbbbcccabbb";
                patterns = {"bbb"};
                result = algo::findAllStringsAhoCorasick(text, patterns);
                REQUIRE(resultEquals({{2, 3, 9}}));
            }
        }
    }

    SECTION("3. Multiple patterns") {
        SECTION("3.1 Non-overlapping patterns") {
            // non-repeating
            text = "abc";
            patterns = {"a", "b", "c"};
            result = algo::findAllStringsAhoCorasick(text, patterns);
            REQUIRE(resultEquals({{0}, {1}, {2}}));

            // repeating
            text = "aabbbbcbabbac";
            patterns = {"a", "b", "c"};
            result = algo::findAllStringsAhoCorasick(text, patterns);
            REQUIRE(resultEquals({
                {0, 1, 8, 11}, 
                {2, 3, 4, 5, 7, 9, 10}, 
                {6, 12}
                }));   
        }

        SECTION("3.2 Partially overlapping patterns") {
            // one pattern's suffix is another pattern's prefix 
            text = "abababa";
            patterns = {"ab", "ba"};
            result = algo::findAllStringsAhoCorasick(text, patterns);
            REQUIRE(resultEquals({
                {0, 2, 4},
                {1, 3, 5}
                }));
        }

        SECTION("3.3 Fully overlapping patterns, repeated patterns") {
            // repeated single-char pattern
            text = "aabbbbcbabbac";
            patterns = {"a", "a", "c"};
            result = algo::findAllStringsAhoCorasick(text, patterns);
            REQUIRE(resultEquals({
                {0, 1, 8, 11}, 
                {0, 1, 8, 11}, 
                {6, 12}
                }));

            // repeated multichar pattern
            text = "aaa";
            patterns = {"aa", "aa"};
            result = algo::findAllStringsAhoCorasick(text, patterns);
            REQUIRE(resultEquals({
                {0, 1}, 
                {0, 1}, 
                }));

            text = "aboaaboa";
            patterns = {"abo", "abo"};
            result = algo::findAllStringsAhoCorasick(text, patterns);
            REQUIRE(resultEquals({
                {0, 4},
                {0, 4},
                }));

            // one pattern is part of another
            text = "ababababa";
            patterns = {"ab", "aba"};
            result = algo::findAllStringsAhoCorasick(text, patterns);
            REQUIRE(resultEquals({
                {0, 2, 4, 6},
                {0, 2, 4}
                }));
        }
    }
}