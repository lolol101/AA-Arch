#pragma once

#include <string>
#include <vector>
#include <unordered_map>

namespace algo::util::boyer_moore {
    // Returns map of last occurence index of each character in the pattern.
    std::unordered_map<char, int> buildBadCharTable(const std::string &pattern);

    // Builds the good suffix table for the Boyer-Moore algorithm.
    std::vector<int> buildGoodSuffixTable(const std::string &pattern);
}

namespace algo {
    /// @brief Finds all occurences of the given string pattern in text using Boyer-Moore algorithm.
    /// @param text string to search for substring in.
    /// @param pattern a string which is needed to be found in text.
    std::vector<size_t> findStringBoyerMoore(const std::string &text, const std::string &pattern);
}