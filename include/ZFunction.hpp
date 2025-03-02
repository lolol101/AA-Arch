#pragma once

#include <vector>
#include <cstdint>
#include <string>
#include <string_view>

namespace algo::util::z {
    /// @brief Helper function for searching for a separator, a character that is not contained in the text.
    char findSeparator(const std::string_view &text, const std::string_view &pattern);

    /// @brief Helper function to calculate z-function.
    std::vector <int> calculateZFunction(const std::string_view &s);
}

namespace algo {
    /// @brief Finds all occurences of the given string pattern using Z-Function.
    /// @param text string to search for substring in.
    /// @param pattern a string which is needed to be found in text.
    std::vector<std::size_t> findStringZFunction(const std::string &text, const std::string& pattern);
}
