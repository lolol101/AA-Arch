#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <vector>
#include <string>
#include <set>

namespace algo {
    std::vector<std::vector<size_t>> findAllStringsAhoCorasick(const std::string& text, const std::set<std::string>& patterns);
    std::vector<size_t> findStringKnuthMorrisPratt(const std::string &text, const std::string& pattern);
    std::vector<size_t> findStringRabinCarp(const std::string &text, const std::string& pattern);
}

#endif // ALGORITHM_HPP