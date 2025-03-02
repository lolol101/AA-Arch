#include "Naive.hpp"
#include <vector>
#include <string>

namespace algo {
    std::vector<size_t> findStringNaive(const std::string &str1, const std::string &str2) {
        std::vector <size_t> result;
        size_t n = str1.size();
        size_t m = str2.size();

        if (m == 0 || n == 0 || m > n) {
            return result;
        }

        for (size_t i = 0; i <= n - m; ++i) {
            bool match = true;

            for (size_t j = 0; j < m; ++j) {
                if (str1[i + j] != str2[j]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                result.push_back(i);
            }
        }

        return result;
    }
}