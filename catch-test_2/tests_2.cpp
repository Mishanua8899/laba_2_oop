#include <fstream>
#include "catch-sample.h"
#include "test_func_task2.h"

/*òåñò ôóíêöèè HTMLEncode - 2 çàäàíèå */
// ÒÅÑÒ Ñ ÄÅÊÎÄÈĞÎÂÀÍÍÎÉ ÏÎÑËÅÄÎÂÀÒÅËÜÍÎÑÒÜŞ
TEST_CASE("Testing HTMLEncode function")
{
	SECTION("string with all encode symbols")
	{
		std::string input = R"(Cat <says> "Meow". M&M’s)";
		std::string expected = R"(Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s)";
		CHECK(HtmlEncode(input) == expected);
	}

	SECTION("multiline example")
	{
		std::string input = R"(Cat <says> "Meow". M&M’s)" "\n"
			R"(Cat <says> "Meow". M&M’s)" "\n"
			R"(Cat <says> "Meow". M&M’s)";
		std::string expected = R"(Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s)" "\n"
			R"(Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s)" "\n"
			R"(Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s)";
		CHECK(HtmlEncode(input) == expected);
	}

	SECTION("empty string") 
	{
		std::string input = "";
		std::string expected = "";
		CHECK(HtmlEncode(input) == expected);
	}

	SECTION("string without encode symbols")
	{
		std::string input = R"(Cat says Meow. M&Ms)";
		std::string expected = R"(Cat says Meow. M&amp;Ms)";
		CHECK(HtmlEncode(input) == expected);
	}

	SECTION("test with encode sequence")
	{
		std::string input = R"(Cat&lt; says&amp; Meow. &amp;M&Ms)";
		std::string expected = R"(Cat&lt; says&amp; Meow. &amp;M&amp;Ms)";
		CHECK(HtmlEncode(input) == expected);
	}

}

