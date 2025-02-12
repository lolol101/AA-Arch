#pragma once

#include "KnuthMorrisPratt.hpp"

#include <string>
#include <vector>

namespace algo::util::kmp {
    /// @brief Calculates LPS (longest prefix which is also suffix) array. 
    /// @brief Each index of the array represents prefix (str[0:i]) and the length of LPS for that.
    /// @param pattern a string is needed to be found.
    /// @param lps an array to store result of function.
    void calculateLPSArray(const std::string& pattern, std::vector<size_t> &lps);
};

namespace algo {
    /// @brief Finds all occurences of the given string pattern.
    /// @param text a string wich contains text.
    /// @param pattern a string is needed to be found.
    std::vector<size_t> findStringKnuthMorrisPratt(const std::string& text, const std::string& pattern);
};
