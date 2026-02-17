#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "test_func_task1.h"

std::vector<double> ReadNumbers(std::istream& fIn)
{
	std::vector<double> result;
	std::string line;
	std::string number;
	double nextNumber = 0;
	if (std::getline(fIn, line))
	{
		std::stringstream lineStream(line);
		while (lineStream >> number)
		{
			try
			{
				nextNumber = std::stod(number);
				result.push_back(nextNumber);
			}
			catch (std::exception& e)
			{
				std::cout << "ERROR" << std::endl;
				std::exit(EXIT_SUCCESS);
			}
		}
	}
	return result;
}

std::vector<double> ProcessNumbers(std::vector<double>& setNumbers)
{
	if (setNumbers.empty())
	{
		return {};
	}

	auto minNumIterator = std::min_element(setNumbers.begin(), setNumbers.end());
	double minNum = *minNumIterator;
	std::vector<double> result;
	std::for_each(setNumbers.begin(), setNumbers.end(), [&](double& number)
		{
			result.push_back(number * minNum);
		});
	return result;
}

void PrintNumbers(const std::vector<double>& setNumbers)
{
	std::for_each(setNumbers.begin(), setNumbers.end(), [](double number)
		{
			std::cout << std::fixed << std::setprecision(3) << number << " ";
		});
	std::cout << std::endl;
}
