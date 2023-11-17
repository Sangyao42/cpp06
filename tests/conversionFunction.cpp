#include <iostream>

class A
{
	public:
		A(std::string str)
		{
			_str = str.c_str();
		}
		operator char() { return atoi(_ch); }
		operator int() { return atoi(_ch); }
		operator float() { return strtof(_ch, NULL); }
		operator double() {
			return strtod(_ch, NULL);
			// return static_cast<double>();
		}

		std::string getStr() { return _str; }
	private:
		// const char *_str;
		std::string _str;
		const char *_ch;
		std::string _strType;
};

int main(void)
{
	A a("2564646553165156156456456");
	std::cout << a.getStr() << std::endl;

	int i = a;
	float f = a;
	double d = a;
	std::cout << i << std::endl;
	std::cout << f << std::endl;
	std::cout << d << std::endl;
	return 0;
}