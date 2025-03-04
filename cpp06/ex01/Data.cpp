#include "Data.hpp"

Data::Data(){}

Data::Data(const Data &copy)
{
	*this = copy;
}

Data &Data::operator=(const Data &copy)
{
	return *this;
}

Data::~Data(){}

void Data::setName(std::string name)
{
	_name = name;
}

std::string Data::getName() const
{
	return _name;
}
