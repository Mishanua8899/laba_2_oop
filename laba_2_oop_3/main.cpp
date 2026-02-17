#include <iostream>

#include "task3.h"

int main()
{

	std::map<std::string, int> stringCounter;
	stringCounter = CountWords(std::cin);
	PrintResult(stringCounter);
	return EXIT_SUCCESS;
}