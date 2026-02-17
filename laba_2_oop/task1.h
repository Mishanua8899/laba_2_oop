#pragma once
#include <iostream>
#include <vector>
std::vector<double> ReadNumbers(std::istream& fIn);
std::vector<double> ProcessNumbers(std::vector<double>& setNumbers);
void PrintNumbers(const std::vector<double>& setNumbers);