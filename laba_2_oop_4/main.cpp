#include <iostream>
#include "task4.h"
int main()
{
	std::set<std::string> BadWords = getBadWords(std::cin);
	std::string filteredText = filterText(std::cin, BadWords);
	std::cout << filteredText;
}