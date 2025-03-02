#pragma once

#include <vector>
#include <string>

namespace algo {

    /// @brief Finds all occurences of the given string pattern using Z-Function.
    /// @param text string to search for substring in.
    /// @param pattern a string which is needed to be found in text.
    std::vector<size_t> findStringNaive(const std::string& text, const std::string& pattern);
}