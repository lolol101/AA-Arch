#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

#include "algorithm.hpp"
#include <iostream>

TEST_CASE( "Aho-Corasick algorithm implementation works as intended") {
    SECTION("1. Empty input") {
        std::string text;
        std::vector<std::string> patterns;
        std::vector<std::vector<size_t>> result;

        auto check_result_empty = [&text, &patterns, &result]() {
            for (const std::vector<size_t> occurences: result) {
                REQUIRE(occurences.empty());
            }
        };

        SECTION("1.1 Empty text") {
            text = "";
            patterns = {"a", "b"};
            std::vector<size_t> result = algo::findAllStringsAhoCorasick(text, patterns);
            check_result_empty();
        }

        SECTION("1.2 Empty pattern list") {
            text = "abcde";
            patterns = {};
            std::vector<size_t> result = algo::findAllStringsAhoCorasick(text, patterns);
            check_result_empty();
        }

        SECTION("1.3 Empty input") {
            text = {};
            patterns = {};
            std::vector<size_t> result = algo::findAllStringsAhoCorasick(text, patterns);
            check_result_empty();
        }
    }

    SECTION("2. Single pattern") {
        SECTION("2.1 Empty pattern") {

        }

        SECTION("2.2 Single Character") {
            SECTION("2.2.1 Appearing single time") {
                
            }
            SECTION("2.2.2 Appearing multiple times") {

            }
        }
        SECTION("2.3 Multiple characters") {
            SECTION("2.3.1 Unique") {

            }
            SECTION("2.3.2 Repeated") {

            }
        }
    }

    SECTION("3. Multiple patterns") {
        SECTION("3.1 Non-overlapping patterns") {
            
        }
        SECTION("3.2 Partially overlapping patterns") {

        }
        SECTION("3.3 Fully overlapping patterns, repeated patterns") {

        }
    }
}