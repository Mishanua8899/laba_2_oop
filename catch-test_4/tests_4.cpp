#include "catch-sample.h"
#include "test_func_task4.h"
#include <fstream>

TEST_CASE("Testing FilterLine function")
{
	SECTION("example with same symbols case")
	{
		std::set<std::string> BadWords{ "stupid", "idiot" };
		std::string example = "This stupid idiot believes that the Sun rotates around the Earth.";
		std::string expexted = "This believes that the Sun rotates around the Earth.";
		CHECK(FilterLine(example, BadWords) == expexted);
	}

	SECTION("example with differend symbols case")
	{
		std::set<std::string> BadWords{ "stupid", "idiot" };
		std::string example = "This stUpid IdiOt believes that the Sun rotates around the Earth.";
		std::string expexted = "This believes that the Sun rotates around the Earth.";
		CHECK(FilterLine(example, BadWords) == expexted);
	}

	SECTION("Bad Words with differend symbols case")
	{
		std::ifstream fileWithBadWords("test_data_for_task4_1.txt");
		std::set<std::string> BadWords = GetBadWords(fileWithBadWords);
		std::string example = "This stUpid IdiOt believes that the Sun rotates around the Earth.";
		std::string expexted = "This believes that the Sun rotates around the Earth.";
		CHECK(FilterLine(example, BadWords) == expexted);
	}

	SECTION("empty input")
	{
		std::set<std::string> BadWords{};
		std::string example = "";
		std::string expexted = "";
		CHECK(FilterLine(example, BadWords) == expexted);
	}
}
