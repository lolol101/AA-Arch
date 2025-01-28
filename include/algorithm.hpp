#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <vector>
#include <string>
#include <set>

namespace algo {
    std::vector<std::vector<size_t>> findAllStringsAhoCorasick(const std::string &text, const std::set<std::string>& patterns);
}

#endif // ALGORITHM_HPP