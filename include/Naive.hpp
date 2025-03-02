#pragma once

#include <vector>
#include <string>

namespace algo {

    /// @brief Функция для нахождения всех вхождений подстроки в строке.
    /// @param str1 Строка, в которой ищется подстрока.
    /// @param str2 Подстрока, которую нужно найти в str1.
    /// @return Вектор индексов всех вхождений str2 в str1.
    std::vector <size_t> findStringNaive(const std::string &str1, const std::string &str2);
}