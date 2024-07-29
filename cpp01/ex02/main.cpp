#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string& stringREF = str;
	std::string* stringPTR = &str;

	std::cout << "The address of the string   : " << &str << std::endl;
	std::cout << "The address of the stringREF: " << &stringREF << std::endl;
	std::cout << "The address of the stringPTR: " << stringPTR << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "The value of the string   : " << str << std::endl;
	std::cout << "The value of the stringREF: " << stringREF << std::endl;
	std::cout << "The value of the stringPTR: " << *stringPTR << std::endl;
	std::cout << "--------------------------------------------" << std::endl;

	return 0;
}
