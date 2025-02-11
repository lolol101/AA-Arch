#include "algorithm.hpp"

namespace {

    /// @brief Calculates LPS (longest prefix which is also suffix) array. 
    /// @brief Each index of the array represents prefix (str[0:i]) and the length of LPS for that.
    /// @param pattern a string is needed to be found.
    /// @param lps an array to store result of function.
    void calculateLPSArray(const std::string& pattern, std::vector<size_t> &lps) {
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
};

namespace algo {

    /// @brief Finds all occurences of the given string pattern.
    /// @param text a string wich contains text.
    /// @param pattern a string is needed to be found.
    std::vector<size_t> findStringKnuthMorrisPratt(const std::string& text, const std::string& pattern) {
        if (pattern.size() == 0 || text.size() == 0) return {};

        std::vector<size_t> occurences;
        std::vector<size_t> lps(pattern.size());

        calculateLPSArray(pattern, lps);

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
};
