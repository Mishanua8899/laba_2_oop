#include <fstream>
#include "catch-sample.h"
#include "test_func_task5.h"


TEST_CASE("Testing ParseURL function")
{
	Protocol protocol = Protocol::UNKNOWN;
	int port = 0;
	std::string host;
	std::string document;

	SECTION("http://example.com")
	{
		std::string url = "http://example.com";
		CHECK(ParseURL(url, protocol, port, host, document) == true);
	}

	SECTION("http://www.mysite.com/docs/document1.html?page=30&lang=en#title")
	{
		std::string url = "http://www.mysite.com/docs/document1.html?page=30&lang=en#title";
		CHECK(ParseURL(url, protocol, port, host, document) == true);
	}

	SECTION("htTp://example.com:8080/index.html")
	{
		std::string url = "htTp://example.com:8080/index.html";
		CHECK(ParseURL(url, protocol, port, host, document) == true);
	}

	SECTION("htp://example.com")
	{
		std::string url = "htp://example.com";
		CHECK(ParseURL(url, protocol, port, host, document) == false);
	}

	SECTION("empty input")
	{
		std::string url = "";
		CHECK(ParseURL(url, protocol, port, host, document) == false);
	}
}

