#include "KnuthMorrisPratt.hpp"

void algo::util::kmp::calculateLPSArray(const std::string& pattern, std::vector<size_t> &lps) {
    if (pattern.length() == 0) {
        lps.clear();
        return;
    }
    lps.resize(pattern.length());
    lps[0] = 0;

    for (int i = 1, matchSize = 0; i < pattern.size();) {
        if (pattern[i] == pattern[matchSize])
            lps[i++] = ++matchSize;
        else if (matchSize != 0)
            matchSize = lps[matchSize - 1];
        else
            lps[i++] = 0;
    }
}

std::vector<size_t> algo::findStringKnuthMorrisPratt(const std::string& text, const std::string& pattern) {
    if (pattern.size() == 0 || text.size() == 0) return {};

    std::vector<size_t> occurences;
    std::vector<size_t> lps(pattern.size());

    util::kmp::calculateLPSArray(pattern, lps);

    for (int i = 0, j = 0; i < text.size();) {
        if (pattern[j] == text[i]) {
            ++i;
            ++j;
        }
        if (j == pattern.size()) {
            occurences.push_back(i - j);
            j = lps[j - 1];
        } 
        else if (i < text.size() && pattern[j] != text[i]) {
            if (j != 0) j = lps[j - 1];
            else ++i;
        }
    }
    return occurences;
}
