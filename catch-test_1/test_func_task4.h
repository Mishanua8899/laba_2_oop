#pragma once
#include <string>
#include <set>
std::string filterText(std::istream& fIn, const std::set<std::string>& BadWords);
std::string filterLine(std::string& line, const std::set<std::string>& BadWords);
std::string ToLowerCase(std::string& word);
std::set<std::string> getBadWords(std::istream& fIn);