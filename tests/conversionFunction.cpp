#include <iostream>
#include <iomanip>

class A
{
	public:
		A(std::string str)
		{
			// _str = str.c_str();
			_ch = str.c_str();
		}
		operator char() { return atoi(_ch); }
		operator int() { return atoi(_ch); }
		operator float() { return strtof(_ch, NULL); }
		operator double() {
			return strtod(_ch, NULL);
			// return static_cast<double>();
		}

		std::string getStr() { return _ch; }
	private:
		// std::string _str;
		const char *_ch;
		std::string _strType;
};

int main(void)
{
	A a("-9999999999999999.1f");
	std::cout << a.getStr() << std::endl;

	int i = a;
	float f = a;
	double d = a;
	std::cout << i << std::endl;
	std::cout << std::fixed << std::setprecision(1) << f << std::endl;
	std::cout << std::fixed << std::setprecision(1) << d << std::endl;

	float f2 = -9999999999999999.1f;
	std::cout << std::fixed << std::setprecision(1) << f2 << std::endl;

	if (f == f2)
		std::cout << "true" << std::endl;
	return 0;
}