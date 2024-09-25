#include "Fixed.hpp"

Fixed::Fixed()
{
	cout << "Default Costructer Called" << endl;
	this->fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &cpy)
{
	cout << "Copy Costructer Called" << endl;
	*this = cpy;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	cout << "Copy Assigment Operator Called" << endl;
	this->fixedPointValue = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	cout << "Destructor Called" << endl;
}

int	Fixed::getRawBits() const
{
	cout << "getRawBits member function called" << endl;
	return (this->fixedPointValue);
}

void	Fixed::setRawBits(int raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedPointValue = raw;
}