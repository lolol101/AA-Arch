#pragma once

#include <string>
#include <set>
#include <vector>

// TODO: split into multiple files? But not a fan of header-source file w/ one function total.
namespace util{

std::string generate_lowercase_string(size_t length);

std::string generate_string_from_alphabet(size_t length, const std::set<char> &alphabet);

std::string generate_string_from_alphabet(size_t length, const std::string &alphabet);


bool isResultValid(const std::string &text, const std::vector<std::string>& patterns, std::vector<std::vector<size_t>> result);
}