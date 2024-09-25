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

Fixed::~Fixed()
{
	cout << "Destructor Called" << endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	cout << "Copy Assigment Operator Called" << endl;
	this->fixedPointValue = other.fixedPointValue;
	return (*this);
}

Fixed::Fixed(int const value)
{
	cout << "Int Costructer Called" << endl;
	this->fixedPointValue = value << this->fractionalBits;
}

Fixed::Fixed(float const value)
{
	cout << "Float Costructer Called" << endl;
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


Fixed	Fixed::operator+(const Fixed& other)
{
	Fixed tmp;
	tmp.fixedPointValue = this->fixedPointValue + other.fixedPointValue;
	return tmp;
}

Fixed	Fixed::operator-(const Fixed& other)
{
	Fixed tmp;
	tmp.fixedPointValue = this->fixedPointValue - other.fixedPointValue;
	return tmp;
}

Fixed	Fixed::operator*(const Fixed& other)
{
	Fixed tmp;
	tmp.fixedPointValue = this->fixedPointValue * other.fixedPointValue / (1 << this->fractionalBits);
	return tmp;
}

Fixed	Fixed::operator/(const Fixed& other)
{
	Fixed tmp;
	tmp.fixedPointValue = this->fixedPointValue / other.fixedPointValue * (1 << this->fractionalBits);
	return tmp;
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->fixedPointValue > other.fixedPointValue);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->fixedPointValue < other.fixedPointValue);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->fixedPointValue >= other.fixedPointValue);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->fixedPointValue <= other.fixedPointValue);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->fixedPointValue == other.fixedPointValue);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->fixedPointValue != other.fixedPointValue);
}


Fixed&	Fixed::operator++() 
{
	this->fixedPointValue++;
	return (*this);
}

Fixed	Fixed::operator++(int) 
{
	Fixed tmp(*this);
	this->fixedPointValue++;
	return (tmp);
}

Fixed&	Fixed::operator--() 
{
	this->fixedPointValue--;
	return (*this);
}

Fixed	Fixed::operator--(int) 
{
	Fixed tmp(*this);
	this->fixedPointValue--;
	return (tmp);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if(a < b)
		return a;
	return b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if(a > b)
		return a;
	return b;
}

const Fixed&	Fixed::min(Fixed const& a, Fixed const& b)
{
	if(a < b)
		return a;
	return b;
}

const Fixed&	Fixed::max(Fixed const& a, Fixed const& b)
{
	if(a > b)
		return a;
	return b;
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
