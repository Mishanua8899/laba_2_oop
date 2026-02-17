#include "task1.h"

int main()
{
    auto numbers = ReadNumbers(std::cin);
    numbers = ProcessNumbers(numbers);
    PrintNumbers(numbers);
    return 0;
}