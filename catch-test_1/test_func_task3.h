#pragma once
#include <map>
#include <string>
std::map<std::string, int> CountWordsOnString(const std::string& line, std::map<std::string, int>& stringCounter);
std::map<std::string, int> CountWords(std::istream& fIn);
void PrintResult(std::map<std::string, int>& stringCounter);
