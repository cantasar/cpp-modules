#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;


	std::cout << std::endl;
    
	Fixed fixed1(42);
    Fixed fixed2(3.14f);

	std::cout << std::endl;
    std::cout << "fixed1: " << fixed1 << std::endl;
    std::cout << "fixed2: " << fixed2 << std::endl;

	std::cout << std::endl;
    bool greaterThan = fixed1 > fixed2;
    bool lessThan = fixed1 < fixed2;
    bool greaterThanOrEqual = fixed1 >= fixed2;
    bool lessThanOrEqual = fixed1 <= fixed2;
    bool equal = fixed1 == fixed2;
    bool notEqual = fixed1 != fixed2;

    std::cout << "fixed1 > fixed2: " << greaterThan << std::endl;
    std::cout << "fixed1 < fixed2: " << lessThan << std::endl;
    std::cout << "fixed1 >= fixed2: " << greaterThanOrEqual << std::endl;
    std::cout << "fixed1 <= fixed2: " << lessThanOrEqual << std::endl;
    std::cout << "fixed1 == fixed2: " << equal << std::endl;
    std::cout << "fixed1 != fixed2: " << notEqual << std::endl;

	std::cout << std::endl;
    Fixed sum = fixed1 + fixed2;
    Fixed difference = fixed1 - fixed2;
    Fixed product = fixed1 * fixed2;
    Fixed quotient = fixed1 / fixed2;

    std::cout << "fixed1 + fixed2: " << sum << std::endl;
    std::cout << "fixed1 - fixed2: " << difference << std::endl;
    std::cout << "fixed1 * fixed2: " << product << std::endl;
    std::cout << "fixed1 / fixed2: " << quotient << std::endl;

	std::cout << std::endl;
    Fixed preIncrement = ++fixed1;
    Fixed postIncrement = fixed1++;

    std::cout << "++fixed1: " << preIncrement << std::endl;
    std::cout << "fixed1++: " << postIncrement << std::endl;
	std::cout << "fixed1: " << fixed1 << std::endl;

	std::cout << std::endl;
    Fixed preDecrement = --fixed1;
    Fixed postDecrement = fixed1--;

    std::cout << "--fixed1: " << preDecrement << std::endl;
    std::cout << "fixed1--: " << postDecrement << std::endl;
	std::cout << "fixed1: " << fixed1 << std::endl;

	std::cout << std::endl;
	std::cout << "fixed1: " << fixed1 << std::endl;
	std::cout << "fixed2: " << fixed2 << std::endl;
    std::cout << "min(fixed1, fixed2): " << Fixed::min(fixed1, fixed2) << std::endl; 
    std::cout << "max(fixed1, fixed2): " << Fixed::max(fixed1, fixed2) << std::endl; 

	std::cout << std::endl;
	std::cout << "fixed1: " << fixed1 << std::endl;

    int intValue;
    int rawBits = fixed1.getRawBits();
    std::cout << "fixed1 raw bits: " << rawBits << std::endl;
    intValue = fixed1.toInt();
    std::cout << "fixed1 to int: " << intValue << std::endl;

    fixed1.setRawBits(1234);
    std::cout << "fixed1 raw bits after setRawBits(1234): "  << fixed1 << std::endl;
    intValue = fixed1.toInt();
    std::cout << "fixed1 to int: " << intValue << std::endl;

	std::cout << std::endl;
	
	return 0;
}