#include <fstream>
#include "catch-sample_1.h"
#include "test_func_task1.h"
#include "test_func_task2.h"
#include "test_func_task3.h"
/*тест функции перемножение на минимальное число в векторе - 1 задание*/
/*TEST_CASE("Testing ProcessNumbers function")
{
	SECTION("non-empty vector with negative minimum")
	{
		std::vector<double> input = { -1, 2, 3 };
		std::vector<double> expected = { 1, -2, -3 };
		REQUIRE(ProcessNumbers(input) == expected);
	}

	SECTION("empty vector")
	{
		std::vector<double> input = { };
		std::vector<double> expected = { };
		REQUIRE(ProcessNumbers(input) == expected);
	}

	SECTION("non-empty vector with positive minimum")
	{
		std::vector<double> input = { 4, 0.5, 20 };
		std::vector<double> expected = { 2, 0.25, 10 };
		REQUIRE(ProcessNumbers(input) == expected);
	}

}*/

/*тест функции HTMLEncode - 2 задание */

/*TEST_CASE("Testing HTMLEncode function")
{
	SECTION("string with all encode symbols")
	{
		std::string input = R"(Cat <says> "Meow". M&MТs)";
		std::string expected = R"(Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s)";
		REQUIRE(HtmlEncode(input) == expected);
	}
	SECTION("multiline example")
	{
		std::string input = R"(Cat <says> "Meow". M&MТs)" "\n"
			R"(Cat <says> "Meow". M&MТs)" "\n"
			R"(Cat <says> "Meow". M&MТs)";
		std::string expected = R"(Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s)" "\n"
			R"(Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s)" "\n"
			R"(Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s)";
		REQUIRE(HtmlEncode(input) == expected);
	}
}*/

/*тест функции CountWordsOnString - 3 задание*/

TEST_CASE("Testing CountWordsOnString function")
{
	SECTION("example with same symbols case")
	{
		std::map<std::string, int> emptyMap;
		std::string input = R"(hello hello hello hello rate rate rate rate)";
		std::map<std::string, int> expected = { {"hello", 4}, {"rate", 4} };
		REQUIRE(CountWordsOnString(input, emptyMap) == expected);
	}

	SECTION("example with differend symbols case")
	{
		std::map<std::string, int> emptyMap;
		std::string input = R"(hEllo Hello hellO heLLo rAte Rate raTe ratE)";
		std::map<std::string, int> expected = { {"hello", 4}, {"rate", 4} };
		REQUIRE(CountWordsOnString(input, emptyMap) == expected);
	}
}

TEST_CASE("Testing CountWords function")
{
	SECTION("test with test_data_for_task3.txt")
	{
		std::ifstream testFile("test_data_for_task3.txt");
		std::map<std::string, int> expected = { {"зайдите", 3}, {"на", 3}, {"официальный", 3}, {"сайт", 3}, {"word", 3} };
		REQUIRE(CountWords(std::cin) == expected);
	}
}