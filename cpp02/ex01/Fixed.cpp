#include "Fixed.hpp"

Fixed::Fixed()
{
	cout << "Default costructer called" << endl;
	this->fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &cpy)
{
	cout << "Copy costructer called" << endl;
	*this = cpy;
}

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	cout << "Copy assigment operator called" << endl;
	this->fixedPointValue = other.fixedPointValue;
	return (*this);
}


Fixed::Fixed(int const value)
{
	cout << "Int costructer called" << endl;
	this->fixedPointValue = value << this->fractionalBits;
}

Fixed::Fixed(float const value)
{
	cout << "Float costructer called" << endl;
	this->fixedPointValue = roundf(value * (1 << this->fractionalBits));
}

float	Fixed::toFloat(void) const
{
	return ((float)this->fixedPointValue / (1 << this->fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->fixedPointValue >> this->fractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}


int	Fixed::getRawBits() const
{
	cout << "getRawBits member function called" << endl;
	return (this->fixedPointValue);
}

void	Fixed::setRawBits(int raw)
{
    cout << "setRawBits member function called" << endl;
    this->fixedPointValue = raw;
}
