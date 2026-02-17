#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

#include "test_func_task3.h"

std::string ToLowerCase(std::string& word)
{
	std::string result = word;
	std::transform(result.begin(), result.end(), result.begin(),
		[](unsigned char c) { return std::tolower(c); });
	return result;
}

std::map<std::string, int> CountWordsOnString(const std::string& line, std::map<std::string, int>& stringCounter)
{
	std::stringstream lineStream(line);
	std::string word;
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

std::map<std::string, int> CountWords(std::istream& fIn)
{
	std::map<std::string, int> stringCounter;
	std::string line;
	while (std::getline(fIn, line))
	{
		stringCounter = CountWordsOnString(line, stringCounter);
	}
	return stringCounter;
}

void PrintResult(std::map<std::string, int>& stringCounter)
{
	for (auto it = stringCounter.begin(); it != stringCounter.end(); ++it)
	{
		std::cout << it->first << ": " << it->second << std::endl;
	}
}
