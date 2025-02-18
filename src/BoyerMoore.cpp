#include "BoyerMoore.hpp"

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

namespace algo::util::boyer_moore {
    std::unordered_map<char, int> buildBadCharTable(const std::string &pattern) {
        std::unordered_map<char, int> badCharTable;
        for (int i = 0; i < pattern.length(); ++i) {
            badCharTable[pattern[i]] = i;
        }
        return badCharTable;
    }

    std::vector<int> buildGoodSuffixTable(const std::string &pattern) {
        int m = pattern.length();
        std::vector<int> goodSuffixTable(m, 0);
        std::vector<int> suffixLengths(m + 1, 0);
    
        for (int i = m - 1; i >= 0; --i) {
            int j = 0;
            while (j <= i && pattern[i - j] == pattern[m - 1 - j]) {
                ++j;
            }
            suffixLengths[i] = j;
        }

        for (int i = 0; i < m; ++i) {
            goodSuffixTable[i] = m;
        }
        for (int i = m - 1; i >= 0; --i) {
            if (suffixLengths[i] == i + 1) {
                for (int j = 0; j < m - 1 - i; ++j) {
                    if (goodSuffixTable[j] == m) {
                        goodSuffixTable[j] = m - 1 - i;
                    }
                }
            }
        }
        for (int i = 0; i < m - 1; ++i) {
            goodSuffixTable[m - 1 - suffixLengths[i]] = m - 1 - i;
        }

        return goodSuffixTable;
    }
}

std::vector<size_t> algo::findStringBoyerMoore(const std::string &text, const std::string &pattern) {
    std::vector<size_t> occurrences;
    int textLength = text.length();
    int patternLength = pattern.length();

    if (patternLength == 0 || textLength < patternLength) return occurrences; // no matches possible

    std::unordered_map<char, int> badCharTable = util::boyer_moore::buildBadCharTable(pattern);
    std::vector<int> goodSuffixTable = util::boyer_moore::buildGoodSuffixTable(pattern);

    int shift = 0; // current shift in the text
    while (shift <= textLength - patternLength) {
        int j = patternLength - 1;

        while (j >= 0 && pattern[j] == text[shift + j]) --j;

        if (j < 0) { // match found
            occurrences.push_back(shift);
            shift += (shift + patternLength < textLength) ? goodSuffixTable[0] : 1;
        } else {
            int badCharShift = j - badCharTable[text[shift + j]];
            int goodSuffixShift = goodSuffixTable[j];
            shift += std::max(badCharShift, goodSuffixShift);
        }
    }

    return occurrences;
}