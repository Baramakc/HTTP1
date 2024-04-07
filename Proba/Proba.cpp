#include <iostream>
#include <cpr/cpr.h>

void get()
{
	cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/get"));
	std::cout << r.text << std::endl;
}

void post()
{
	std::string text;
	std::cout << "Input text for headers: "; std::getline(std::cin, text);

	cpr::Response r = cpr::Post(cpr::Url{"http://httpbin.org/post"},
		cpr::Header{{"text", text.c_str()}});

	std::cout << r.text << std::endl;
}

void del() {
	cpr::Response r = cpr::Delete(cpr::Url{"http://httpbin.org/post"});

	std::cout << r.text << std::endl;
}

int main()
{
	std::string buffer;
	while(buffer != "exit")
	{
		std::cout << "Input command: "; std::getline(std::cin, buffer);
		if (buffer == "get") get();
		if (buffer == "post") post();
	}
}
