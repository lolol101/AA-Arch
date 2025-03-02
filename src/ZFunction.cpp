#include <ZFunction.hpp>
#include <unordered_set>
#include <string_view>
#include <stdexcept>

namespace algo::util::z {
    /// @brief Helper function for searching for a separator, a character that is not contained in the text.
    char findSeparator(const std::string_view &text, const std::string_view &pattern) {
        std::unordered_set<char> used_chars(text.begin(), text.end());
        used_chars.insert(pattern.begin(), pattern.end());
        for (char c = 1; c < 127; c++) {
            if (used_chars.find(c) == used_chars.end()) {
                return c;
            }
        }
        throw std::runtime_error("Couldn't find a suitable separator");
    }

    /// @brief Helper function to calculate z-function.
    std::vector <int> calculateZFunction(const std::string_view &s) {
        if (s.size() == 0) {
            return {};
        }
        int intStringSize = static_cast<int>(s.size());
        std::vector <int> z(s.size(), 0);
        z[0] = intStringSize;
        int leftPointer = 0;
        int rightPointer = -1;
        for (int i = 1; i < intStringSize; ++i) {
            if (i < rightPointer) {
                z[i] = std::min(z[i - leftPointer], rightPointer - i);
            }
            while (i + z[i] < intStringSize && s[i + z[i]] == s[z[i]]) {
                ++z[i];
            }
            if (i + z[i] > rightPointer) {
                rightPointer = i + z[i];
                leftPointer = i;
            }
        }
        return z;
    }
}

namespace algo {
    /// @brief Finds all occurences of the given string pattern using Z-Function.
    /// @param text string to search for substring in.
    /// @param pattern a string which is needed to be found in text.
    std::vector<std::size_t> findStringZFunction(const std::string &text, const std::string& pattern) {
        if (text.empty() || pattern.empty()) {
            return {};
        }
        char sep = util::z::findSeparator(text, pattern);
        std::string combinedString = pattern + sep + text;
        std::vector <int> z = util::z::calculateZFunction(combinedString);
        std::vector <std::size_t> result;
        int intPatternSize = static_cast<int>(pattern.size());
        for (std::size_t i = pattern.size() + 1; i < combinedString.size(); ++i) {
            if (z[i] == intPatternSize) {
                result.push_back(i - pattern.size() - 1);
            }
        }
        return result;
    }
}
