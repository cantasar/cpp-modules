#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
using std::cout;
using std::endl;

class Fixed {
private:
	int fixedPointValue;
	static const int fractionalBits = 8;

public:
	Fixed ();
	Fixed (const Fixed& other);
	~Fixed ();

	Fixed& operator=(const Fixed& other);

	Fixed (int const value);
	Fixed (float const value);
	float	toFloat(void) const;
	int		toInt(void) const;

	bool	operator> (const Fixed& other) const;
	bool	operator< (const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;

	Fixed	operator+(const Fixed& other);
	Fixed	operator-(const Fixed& other);
	Fixed	operator*(const Fixed& other);
	Fixed	operator/(const Fixed& other);

	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);

	static Fixed&	min(Fixed& a, Fixed& b);
	static Fixed&	max(Fixed& a, Fixed& b);
	static const Fixed&	min(Fixed const& a, Fixed const& b);
	static const Fixed&	max(Fixed const& a, Fixed const& b);

	int		getRawBits() const;
	void	setRawBits(int raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif