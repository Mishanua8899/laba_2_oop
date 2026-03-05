#include "task1.h"

int main()
{
    std::vector<double> numbers;
    try 
    {
        numbers = ReadNumbers(std::cin);
    }
    catch (...)
    {
        std::cout << "ERROR" << std::endl;
        return EXIT_SUCCESS;
    }
    numbers = ProcessNumbers(numbers);
    PrintNumbers(numbers);
    return EXIT_SUCCESS;
}