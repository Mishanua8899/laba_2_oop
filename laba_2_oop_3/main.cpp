#include <iostream>
#include <sstream>
#include <io.h>
#include <fstream>
#include <fcntl.h>
#include "task3.h"

int main()
{
	setlocale(LC_ALL, "ru");
	// std::wstring contents = ReadFile("test.txt");
	_setmode(_fileno(stdin), _O_U16TEXT);
	std::cout.imbue(std::locale(""));
	std::map<std::wstring, int> stringCounter;
	stringCounter = CountWords(std::wcin);
	PrintResult(stringCounter);
	return EXIT_SUCCESS;
}