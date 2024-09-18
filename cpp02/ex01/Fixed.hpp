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

	int		getRawBits() const;
	void	setRawBits(int raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif