#include <iostream>
#include <string>
#include <cstdlib>

int main(void)
{
	// char c = 'a';
	std::string str = "42.0f";
	const char *c = str.c_str();
	// int i = static_cast<int>(str);
	int i;
	float f = 0.0f;
	double d = 0.0;
	try
	{
		i = atoi(c);

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		f = strtof(c, NULL);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		d = strtod(c, NULL);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << i << std::endl;
	std::cout << f << std::endl;
	std::cout << d << std::endl;
	return 0;
}
