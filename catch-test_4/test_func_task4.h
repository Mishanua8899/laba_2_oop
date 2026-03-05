#pragma once
#include <string>
#include <set>
std::string FilterText(std::istream& fIn, const std::set<std::string>& BadWords);
std::string FilterLine(std::string& line, const std::set<std::string>& BadWords);
std::string ToLowerCase(std::string word);
std::set<std::string> GetBadWords(std::istream& fIn);