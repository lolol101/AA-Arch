#pragma once

#include <vector>
#include <cstdint>
#include <string>
#include <string_view>

namespace algo::util::rabincarp {
    /// @brief Helper function to compute hash of the string.
    uint64_t computeHash(const std::string_view &s, const uint64_t prime, const uint64_t base);

    /// @brief Helper function to precompute powers of BASE modulo PRIME. 
    std::vector<uint64_t> precomputePowers(size_t stringLength, const uint64_t prime, const uint64_t base);
}

namespace algo {
    /// @brief Finds all occurences of the given string pattern using rolling hash Rabin-Carp algorithm.
    /// @param text string to search for substring in.
    /// @param pattern a string which is needed to be found in text.
    std::vector<size_t> findStringRabinCarp(const std::string &text, const std::string& pattern);
}
