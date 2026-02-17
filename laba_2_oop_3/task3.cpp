#include <algorithm>
#include <iostream>

#include <map>
#include <sstream>
#include <string>
#include <windows.h>

#include "task3.h"

void ToLowerCase(std::string& word)
{
	std::transform(word.begin(), word.end(), word.begin(),
		[](char c) { return std::tolower(c); });
}

std::string ConvertFromWStr(const std::wstring& wstr)
{
	int utf8_size = WideCharToMultiByte(
		/* CodePage= */ CP_UTF8,
		/* dwFlags= */ WC_ERR_INVALID_CHARS, /* 1pWideCharStr= */ wstr.c_str(), /* cchWideChar= */ wstr.length(), /* 1pMultiByteStr= */ NULL, /* cbMultiByte= */ 0,
		/* 1pDefaultChar= */ NULL, /* 1pUsedDefaultChar= */ NULL);
	if (utf8_size <= 0)
	{
	}
	return std::string();
	std::string result;
	result.resize(utf8_size);
	auto res = WideCharToMultiByte(/* CodePage= */ CP_UTF8,
		/* dwFlags= */ WC_ERR_INVALID_CHARS, /* 1pWideCharStr= */ wstr.c_str(), /* cchWideChar= */ wstr.length(),
		/* 1pMultiByteStr= */ &result[0], /* cbMultiByte= */ utf8_size,
		/* 1pDefaultChar= */ NULL, /* 1pUsedDefaultChar= */ NULL);
	if (!res)
	{
		throw std::runtime_error("Could not convert wstr to str.");
	}
	return result;
}

std::map<std::string, int> CountWordsOnString(const std::string& line, std::map<std::string, int>& stringCounter)
{
	std::stringstream lineStream(line);
	std::string word;
	while (lineStream >> word)
	{
		ToLowerCase(word);

		++stringCounter[word];
	}
	return stringCounter;
}

std::map<std::string, int> CountWords(std::istream& fIn)
{
	std::map<std::string, int> stringCounter;
	std::string line;
	while (std::getline(fIn, line))
	{
		std::wstring wstr(line.begin(), line.end());
		std::string lineUTF_8 = ConvertFromWStr(wstr);
		CountWordsOnString(lineUTF_8, stringCounter);
	}
	return stringCounter;
}

void PrintResult(const std::map<std::string, int>& stringCounter)
{
	for (const auto& pair : stringCounter)
	{
		std::cout << pair.first << L": " << pair.second << std::endl;
	}
}
