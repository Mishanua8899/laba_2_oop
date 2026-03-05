#include <iostream>
#include <regex>

#include "task5.h"

std::string ToLowerCase(std::string word)
{
	std::transform(word.begin(), word.end(), word.begin(),
		[](unsigned char c) { return std::tolower(c); });
	return word;
}

Protocol SetProtocol(std::string& prot)
{
	Protocol protocol;
	if (prot == "http")
	{
		protocol = Protocol::HTTP;
	}
	else if (prot == "https")
	{
		protocol = Protocol::HTTPS;
	}
	else if (prot == "ftp")
	{
		protocol = Protocol::FTP;
	}
	return protocol;
}

int SetPort(const Protocol &protocol,const std::cmatch &result)
{
	int port = 0;
	if (result[3].matched)
	{
		std::string number = result[3].str();
		number.erase(number.begin());
		port = std::stoi(number);
	}
	else
	{
		switch (protocol)
		{
		case Protocol::HTTP:
			port = 80;
			break;
		case Protocol::HTTPS:
			port = 443;
			break;
		case Protocol::FTP:
			port = 21;
			break;
		}
	}
}

std::string SetHost(const std::cmatch& result)
{
	return result[2].str();
}

std::string SetDocument(const std::cmatch& result)
{
	std::string document;
	if (result[4].matched)
	{
		document = result[4].str();
		document.erase(document.begin());
	}
	return document;
}

bool ParseURL(std::string const& url, Protocol& protocol, int& port, std::string& host, std::string& document)
{
	std::cmatch result;
	std::regex regular(R"(^(http|https|ftp)://([a-z0-9.-]+)(:[0-9]{1,5})?(/[^]*)?$)", std::regex::icase);

	if (std::regex_match(url.c_str(), result, regular))
	{
		std::string prot = result[1].str();
		prot = ToLowerCase(prot);
		protocol = SetProtocol(prot);
		
		host = SetHost(result);

		port = SetPort(protocol, result);

		if (port > 65536)
		{
			return false;
		}

		document = SetDocument(result);
		
	}
	else
	{
		return false;
	}

	return true;
}

