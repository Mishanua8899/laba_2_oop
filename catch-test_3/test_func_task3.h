#pragma once
#include <map>
#include <string>
std::map<std::wstring, int> CountWordsOnString(const std::wstring& line, std::map<std::wstring, int>& stringCounter);
std::map<std::wstring, int> CountWords(std::wistream& fIn);
void PrintResult(std::map<std::wstring, int>& stringCounter);
std::wstring ReadFile(const char* filename);