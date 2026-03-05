#include <iostream>

#include "task5.h";

int main()
{
	std::string url;
	if (std::getline(std::cin, url))
	{
		Protocol protocol = Protocol::UNKNOWN;
		int port = 0;
		std::string host;
		std::string document;

		if (ParseURL(url, protocol, port, host, document))
		{
			std::cout << "HOST: " << host << std::endl;
			std::cout << "PORT: " << port << std::endl;
			std::cout << "DOC: " << document << std::endl;
		}
		else
		{
			std::cout << "ERROR" << std::endl;
			return EXIT_SUCCESS;
		}
	}
}