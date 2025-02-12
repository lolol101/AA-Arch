#pragma once

#include "util.hpp"

#include <set>
#include <vector>
#include <string>
#include <functional>

namespace test::singlepattern {

using FuncType = std::function<std::vector<size_t>(const std::string &, const std::string &)>;

/// @brief Runs corner case tests for single-pattern search function in which not all required input is present.
void test_findSingleString_EmptyInput(FuncType findSingleString);

/// @brief Runs corner case tests for a multipattern search function in case where only one pattern is provided.
void test_findSingleString_SinglePattern(FuncType findSingleString);
}


namespace test::multipattern {

using FuncType = std::function<std::vector<std::vector<size_t>>(const std::string &, const std::set<std::string> &)>;

/// @brief Runs corner case tests for multipattern search function in which not all required input is present.
void test_findAllStrings_EmptyInput(FuncType findAllStrings);

/// @brief Runs corner case tests for a multipattern search function in case where only one pattern is provided.
void test_findAllStrings_SinglePattern(FuncType findAllStrings);

/// @brief Runs corner case tests for a multipattern search function in case where only one pattern is provided.
void test_findAllStrings_MultiPattern(FuncType findAllStrings);
}