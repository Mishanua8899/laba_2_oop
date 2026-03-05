#include <fstream>
#include "catch-sample.h"
#include "test_func_task1.h"


/*тест функции перемножение на минимальное число в векторе - 1 задание*/

// обработка ввода букв
TEST_CASE("Testing ProcessNumbers function")
{

	SECTION("correct input")
	{
		std::ifstream file("output_test_2.txt");
		std::vector<double> expected = { 1, 2, 3 };
		CHECK(ReadNumbers(file) == expected);
	}

	SECTION("input with incorrect symbols")
	{
		std::ifstream file("output_test.txt");
		CHECK_THROWS_AS(ReadNumbers(file), std::runtime_error);
	}

	SECTION("non-empty vector with negative minimum")
	{
		std::vector<double> input = { -1, 2, 3 };
		std::vector<double> expected = { 1, -2, -3 };
		CHECK(ProcessNumbers(input) == expected);
	}

	SECTION("empty vector")
	{
		std::vector<double> input = { };
		std::vector<double> expected = { };
		CHECK(ProcessNumbers(input) == expected);
	}

	SECTION("non-empty vector with positive minimum")
	{
		std::vector<double> input = { 4, 0.5, 20 };
		std::vector<double> expected = { 2, 0.25, 10 };
		CHECK(ProcessNumbers(input) == expected);
	}

	SECTION("non-empty vector with negative numbers")
	{
		std::vector<double> input = { -1, -2, -3, -4 };
		std::vector<double> expected = { 4, 8, 12, 16 };
		CHECK(ProcessNumbers(input) == expected);
	}

}


