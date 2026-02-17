#include <iostream>
#include <algorithm>
#include <sstream>
#include <set>
#include <string>

#include "test_func_task4.h"
#include "test_func_task3.h"

std::set<std::string> getBadWords(std::istream& fIn)
{
	std::set<std::string> BadWords;
	std::string line;
	if (std::getline(fIn, line))
	{
		std::stringstream lineStream(line);
		std::string word;
		while (lineStream >> word)
		{
			BadWords.insert(word);
		}
	}
	return BadWords;
}

std::string filterLine(std::string& line, const std::set<std::string>& BadWords)
{
	std::stringstream lineStream(line);
	std::string word;
	std::string filteredLine;
	bool firstWord = true;
	while (lineStream >> word)
	{
		std::string toLowerWord = ToLowerCase(word);
		auto search = BadWords.find(toLowerWord);
		if (search == BadWords.end())
		{
			if (!firstWord)
			{
				filteredLine += ' ';
			}
			filteredLine += word;
			firstWord = false;
		}
	}
	return filteredLine;
}

std::string filterText(std::istream& fIn, const std::set<std::string>& BadWords)
{
	std::string line;
	std::string result;
	while (std::getline(fIn, line))
	{
		std::string filteredLine = filterLine(line, BadWords);
		if (!filteredLine.empty()) {
			result += filteredLine + "\n";
		}
	}
	return result;
}

