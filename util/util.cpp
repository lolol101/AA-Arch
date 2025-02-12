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

bool util::isResultValid_MultiPattern(const std::string &text, const std::set<std::string> &patterns, std::vector<std::vector<size_t>>& result)
{
    if (result.size() != patterns.size()) return false; // TODO: maybe exceptions?

    auto it = patterns.begin(); 
    for (size_t i = 0; i < patterns.size(); i++) {
        const std::string &pattern = *it;
        if (!util::isResultValid_SinglePattern(text, pattern, result[i])) return false;
        std::advance(it, 1);
    }

    return true;
}

bool util::isResultValid_SinglePattern(const std::string &text, const std::string &pattern, std::vector<size_t>& result) {
    std::vector<size_t> mockOccurences;
    for (size_t pos = 0; pos <= text.size() - pattern.size(); pos++) {
        if (pattern == std::string_view(text.data() + pos, pattern.size())) {
            mockOccurences.push_back(pos);
        }
    }

    return mockOccurences == result;
}
