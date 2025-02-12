#include "RabinCarp.hpp"

#include <string>
#include <string_view>
#include <vector>
#include <cstdint>

namespace algo::util::rabincarp {
    // Constants for hashing
    const uint64_t PRIME = 1000000007;
    const uint64_t BASE = 256; // number of possible characters // TODO: can hide them in unnamed namespace if needed

    uint64_t computeHash(const std::string_view &s, const uint64_t prime, const uint64_t base) {
        uint64_t hash = 0;
        for (char c : s) {
            hash = (hash * base + static_cast<uint64_t>(c)) % prime;
        }
        return hash;
    }

    std::vector<uint64_t> precomputePowers(size_t stringLength, const uint64_t prime, const uint64_t base) {
        std::vector<uint64_t> powers(stringLength, 1);
        for (size_t i = 1; i < stringLength; ++i) {
            powers[i] = (powers[i - 1] * base) % prime;
        }
        return powers;
    }
}

namespace algo {
    /// @brief Finds all occurences of the given string pattern using rolling hash Rabin-Carp algorithm.
    /// @param text string to search for substring in.
    /// @param pattern a string which is needed to be found in text.
    std::vector<size_t> findStringRabinCarp(const std::string &text, const std::string& pattern) {
        using namespace util::rabincarp;

        std::vector<size_t> result;

        if (pattern.empty() || text.empty() || pattern.size() > text.size()) {
            return result; // No matches possible
        }

        size_t n = text.size();
        size_t m = pattern.size();

        std::string_view textView(text);
        std::string_view patternView(pattern);

        uint64_t patternHash = computeHash(patternView, PRIME, BASE);
        uint64_t textHash = computeHash(textView.substr(0, m), PRIME, BASE);
        std::vector<uint64_t> powers = precomputePowers(m, PRIME, BASE);

        for (size_t i = 0; i <= n - m; ++i) {
            if (textHash == patternHash && textView.substr(i, m) == patternView) {
                result.push_back(i);
            }

            if (i < n - m) {
                textHash = (textHash - static_cast<uint64_t>(text[i]) * powers[m - 1] % PRIME + PRIME) % PRIME;
                textHash = (textHash * BASE + static_cast<uint64_t>(text[i + m])) % PRIME;
            }
        }

        return result;
    }
}
