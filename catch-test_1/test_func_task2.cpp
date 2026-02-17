#include <algorithm>
#include <iostream>
#include <string>

#include "test_func_task2.h"

std::string HtmlEncode(std::string const& text)
{
	std::string result;

	std::for_each(text.begin(), text.end(), [&](char ch) {
		switch (ch)
		{
		case '"':
			result += "&quot;";
			break;
		case '’':
			result += "&apos;";
			break;
		case '<':
			result += "&lt;";
			break;
		case '>':
			result += "&gt;";
			break;
		case '&':
			result += "&amp;";
			break;
		default:
			result += ch;
			break;
		}
		});
	return result;
}



std::string GetHTMLEncodeText(std::istream& fIn)
{
	std::string line;
	std::string result;
	while (std::getline(fIn, line))
	{
		result += HtmlEncode(line) + "\n";
	}

	return result;
}