#include "task2.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string GetHTMLEncodeText(std::istream& stream)
{
	std::string line;
	std::string result;
	while (std::getline(stream, line))
	{
		result += HtmlEncode(line) + "\n";
	}

	return result;
}

std::string HtmlEncode(std::string const& text)
{
	std::string result;
	bool isEncode = false;
	int counter = 0;
	std::vector<std::string> htmlEntities = { "&quot;", "&apos;", "&lt;", "&gt;", "&amp;" };
	std::string entity = "";
	std::for_each(text.begin(), text.end(), [&](char ch) {
		auto start = std::begin(text) + counter;
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
			for (auto iter = start; iter != std::end(text) && (iter - start) < 5; ++iter)
			{
				if (*iter == ';')
				{
					entity.push_back(*iter);
					isEncode = true;
					break;
				}
				entity.push_back(*iter);
			}
			if (isEncode)
			{
				if (std::find(htmlEntities.begin(), htmlEntities.end(), entity) != std::end(htmlEntities))
				{
					isEncode = false;
					result += "&";
					entity.erase(entity.begin(), entity.end());
					break;
				}
			}

			result += "&amp;";
			break;
		default:
			result += ch;
			break;
		}
		counter += 1;
	});
	return result;
}
