#include <fstream>
#include "catch-sample.h"
#include "test_func_task3.h"


/*тест функции перемножение на минимальное число в векторе - 1 задание*/

// обработка ввода букв
/*тест функции CountWordsOnString - 3 задание*/

TEST_CASE("Testing CountWordsOnString function")
{
	SECTION("example with same symbols case")
	{
		std::map<std::wstring, int> emptyMap;
		std::wstring input = L"hello hello hellO hello rate raTe rate rate";
		std::map<std::wstring, int> expected = { {L"hello", 4}, {L"rate", 4} };
		CHECK(CountWordsOnString(input, emptyMap) == expected);
	}

	SECTION("example with differend symbols case")
	{
		std::map<std::wstring, int> emptyMap;
		std::wstring input = L"hEllo Hello hellO heLLo rAte Rate raTe Рате рате";
		std::map<std::wstring, int> expected = { {L"hello", 4}, {L"rate", 3}, {L"рате", 2}};
		CHECK(CountWordsOnString(input, emptyMap) == expected);
	}

	SECTION("test with test_data_for_task3.txt")
	{
		std::map<std::wstring, int> emptyMap;
		std::wstring data = ReadFile("test_data_for_task3.txt");
		std::map<std::wstring, int> expected = { {L"word", 12}, {L"pab", 6}};
		CHECK(CountWordsOnString(data, emptyMap) == expected);
	}

	SECTION("empty input")
	{
		std::map<std::wstring, int> emptyMap;
		std::wstring input = L"";
		std::map<std::wstring, int> expected = { };
		CHECK(CountWordsOnString(L"", emptyMap) == expected);
	}
}



