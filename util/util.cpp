#include "util.hpp"
#include <vector>
#include <random>
#include <string_view>
#include <iostream>

std::string util::generateStringFromAlphabet(size_t length, const std::set<char> &alphabet)
{
    std::vector<char> string_content(length); // TODO: size check: posix_fallocate?
    std::vector<char> alphabet_content(alphabet.begin(), alphabet.end());
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, alphabet.size() - 1);

    for (char &c: string_content) {
        c = alphabet_content[dis(gen)];
    }

    return std::string(string_content.begin(), string_content.end());
}

std::string util::generateStringFromAlphabet(size_t length, const std::string &alphabet)
{
    return util::generateStringFromAlphabet(length, std::set<char>(alphabet.begin(), alphabet.end()));
}

bool util::isResultValid(const std::string &text, const std::vector<std::string> &patterns, std::vector<std::vector<size_t>> result)
{
    if (result.size() != patterns.size()) return false; // TODO: maybe exceptions?

    for (size_t i = 0; i < patterns.size(); i++) {
        const std::string &pattern = patterns[i];
        std::vector<size_t> mockOccurences;
        for (size_t pos = 0; pos <= text.size() - pattern.size(); pos++) {
            if (pattern == std::string_view(text.data() + pos, pattern.size())) {
                    mockOccurences.push_back(pos);
            }
        }
        std::cerr << "Mock occurences: ";
        for (auto v: mockOccurences) std::cerr << v << ' ';
        std::cerr << '\n';
        std::cerr << "Result: ";
        for (auto v : result[i]) {
            std::cerr << v << ' ';
        }
        std::cerr << '\n';
        if (mockOccurences != result[i]) return false;
    }

    return true;
}
