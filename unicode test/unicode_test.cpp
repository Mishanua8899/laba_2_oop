#include <algorithm>
#include <cwctype>      // для std::towlower
#include <sstream>
#include <string>
#include <iostream>
#include <io.h>
#include <fcntl.h>

// Преобразование широкой строки к нижнему регистру
std::string ToLowerCase(std::string word)  // принимаем копию, чтобы не портить оригинал
{
    std::transform(word.begin(), word.end(), word.begin(),
        [](wchar_t c) { return std::towlower(c); });
    return word;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    // Устанавливаем режим UTF-16 для консоли (только для Windows)

    std::string line;
    std::getline(std::cin, line);   // читаем всю строку, включая пробелы

    std::cout << ToLowerCase(line) << std::endl;

    return 0;
}