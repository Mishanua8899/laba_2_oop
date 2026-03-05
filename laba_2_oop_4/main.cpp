#include <iostream>

#include "task4.h"
int main()
{
	std::set<std::string> BadWords = GetBadWords(std::cin);
	std::string filteredText = FilterText(std::cin, BadWords);
	std::cout << filteredText;
}