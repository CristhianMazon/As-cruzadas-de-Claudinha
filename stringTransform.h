#ifndef STRING_TRANSFORM_H
#define STRING_TRANSFORM_H

#include <string>
#include <algorithm>

// Função para transforma string em UPPERCASE.
std::string toUpperCase(const std::string &str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

#endif