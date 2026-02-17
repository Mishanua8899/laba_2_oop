#include <iostream>
#include "task2.h"

int main()
{
    std::string encoded = GetHTMLEncodeText(std::cin);
    std::cout << encoded;
    return 0;
}