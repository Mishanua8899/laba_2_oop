#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <cwctype>  
#include <fstream>
#include "test_func_task3.h"

std::wstring ReadFile(const char* filename) {
	std::wifstream wif(filename);
	std::locale myLoc("");
	wif.imbue(myLoc);
	std::basic_stringstream<wchar_t> wss;
	wss << wif.rdbuf();
	return wss.str();
}

std::wstring ToLowerCase(std::wstring word) 
{
	std::transform(word.begin(), word.end(), word.begin(),
		[](wchar_t c) { return std::towlower(c); });
	return word;
}

std::map<std::wstring, int> CountWordsOnString(const std::wstring& line, std::map<std::wstring, int>& stringCounter)
{
	std::wstringstream lineStream(line);
	std::wstring word;
	while (lineStream >> word)
	{
		word = ToLowerCase(word);
		auto search = stringCounter.find(word);
		if (search != stringCounter.end())
		{
			++stringCounter[word];
		}
		else
		{
			stringCounter.insert({ word, 1 });
		}
	}
	return stringCounter;
}

std::map<std::wstring, int> CountWords(std::wistream& fIn)
{
	std::map<std::wstring, int> stringCounter;
	std::wstring line;
	while (std::getline(fIn, line))
	{
		stringCounter = CountWordsOnString(line, stringCounter);
	}
	return stringCounter;
}

void PrintResult(std::map<std::wstring, int>& stringCounter)
{
	for (auto it = stringCounter.begin(); it != stringCounter.end(); ++it)
	{
		std::wcout << it->first << ": " << it->second << std::endl;
	}
}
