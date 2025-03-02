#include "LCS.hpp"
#include <vector>
#include <string>

namespace algo {

    std::vector <size_t> findStringLCS(const std::string &str1, const std::string &str2) {
        std::vector <size_t> result;
        size_t n = str1.size();
        size_t m = str2.size();

        if (m == 0 || n == 0 || m > n) {
            return result;
        }

        // DP table for storing LCS lengths
        std::vector <std::vector<size_t>> dp(n + 1, std::vector<size_t>(m + 1, 0));

        // Fill DP table
        for (size_t i = 1; i <= n; ++i) {
            for (size_t j = 1; j <= m; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            }
        }

        // Find all occurrences where LCS matches the full length of str2
        for (size_t i = 0; i <= n; ++i) {
            if (dp[i][m] == m) {
                result.push_back(i - m);
            }
        }

        return result;
    }
}
