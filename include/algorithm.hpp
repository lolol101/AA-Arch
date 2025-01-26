#pragma once

#include <cstddef>
#include <string>
#include <vector>

namespace algo{

/// @brief Searches for all occurences of provided patterns in text.
/// @param text Provided text to search for patterns in.
/// @param patterns List of strings to search for.
/// @return Vector of vectors, where each inner vector contains all indexes of occurences of pattern with the same index in text, in order.
std::vector<std::vector<size_t>> findAllStringsAhoCorasick(
    const std::string &text,
    const std::vector<std::string> &patterns
);

}

