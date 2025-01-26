#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <vector>
#include <string>

namespace algo {
    std::vector<size_t> findAllStringsAhoCorasick(const std::string &text, const std::vector<std::string>& patterns);
}

#endif // ALGORITHM_HPP