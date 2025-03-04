#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	*this = obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
	(void)obj;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &str)
{
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff" || str == "inff" || str == "inf")
		nanCases(str);
	else
	{
		char type = determineType(str);

		if (type == 'c')
			castChar(str);
		else if (type == 'd')
			castDouble(str);
		else if (type == 'i')
			castInt(str);
		else if (type == 'f')
			castFloat(str);
		else if (type == 'x')
			nothingType();
	}
}

void nanCases(const std::string &str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (str == "nanf")
	{
		std::cout << "float: " << str << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "-inff")
	{
		std::cout << "float: " << str << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (str == "+inff")
	{
		std::cout << "float: " << str << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else
	{
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
	}
}

char determineType(const std::string &str)
{
	size_t i = 0;
	bool hasDecimalPoint = false;

	if (!std::isdigit(str.c_str()[0]) && str.length() == 1)
		return 'c';

	if (str[i] == '+' || str[i] == '-')
		i++;

	while (str[i])
	{
		if (str[i] == '.')
		{
			if (hasDecimalPoint)
				return 'x';
			hasDecimalPoint = true;
		}
		else if (!std::isdigit(str[i]))
		{
			if (i == str.length() - 1 && str[i] == 'f')
				return 'f';
			return 'x';
		}
		i++;
	}

	if (hasDecimalPoint)
		return 'd';
	return 'i';
}

void castChar(std::string str)
{
	char c = str[0];
	if (c >= 32 && c <= 126)
	{
		int i = static_cast<int>(c);
		float f = static_cast<float>(c);
		double d = static_cast<double>(c);
		
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	} 
	else
	{
		std::cout << "This character isn't printable" << std::endl;
	}
}

void castInt(std::string str)
{
	int value = static_cast<int>(std::strtod(str.c_str(), NULL));
	char c = static_cast<char>(value);
	float f = static_cast<float>(value);
	double d = static_cast<double>(value);

	if (value >= 32 && value <= 126)
		std::cout << "char: " << "'" << c << "'"<< std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << value << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void castDouble(std::string str)
{
	double value = static_cast<double>(std::strtod(str.c_str(), NULL));
	char c = static_cast<char>(value);
	int i = static_cast<int>(value);
	float f = static_cast<float>(value);

	if (value >= 32 && value <= 126)
		std::cout << "char: " << "'" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}

void castFloat(std::string str)
{
	float value = static_cast<float>(std::strtod(str.c_str(), NULL));
	char c = static_cast<char>(value);
	int i = static_cast<int>(value);
	double d = static_cast<double>(value);
	
	if (value >= 32 && value <= 126)
		std::cout << "char: " << "'" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void nothingType()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}