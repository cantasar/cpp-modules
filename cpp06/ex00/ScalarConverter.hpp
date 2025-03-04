#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>

class ScalarConverter
{
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &obj);
	ScalarConverter &operator=(const ScalarConverter &obj);
	~ScalarConverter();

	static void convert(const std::string &str);
};

void nanCases(const std::string &str);
char determineType(const std::string& str);
void castChar(std::string str);
void castInt(std::string str);
void castFloat(std::string str);
void castDouble(std::string str);
void nothingType();

#endif