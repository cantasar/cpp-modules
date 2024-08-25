#include "Fixed.hpp"
#include <iostream>

int main() {
    // Test constructor
    Fixed fixed1;
    Fixed fixed2(42);
    Fixed fixed3(3.14f);

    std::cout << "fixed1: " << fixed1 << std::endl;
    std::cout << "fixed2: " << fixed2 << std::endl;
    std::cout << "fixed3: " << fixed3 << std::endl;

    // Test copy constructor
    Fixed fixed4(fixed2);
    std::cout << "fixed4 (copy of fixed2): " << fixed4 << std::endl;

    // Test assignment operator
    Fixed fixed5;
    fixed5 = fixed3;
    std::cout << "fixed5 (assigned from fixed3): " << fixed5 << std::endl;

    // Test toFloat and toInt functions
    float floatValue = fixed3.toFloat();
    int intValue = fixed2.toInt();
    std::cout << "fixed3 to float: " << floatValue << std::endl;
    std::cout << "fixed2 to int: " << intValue << std::endl;

    // Test comparison operators
    bool greaterThan = fixed2 > fixed3;
    bool lessThan = fixed2 < fixed3;
    bool greaterThanOrEqual = fixed2 >= fixed3;
    bool lessThanOrEqual = fixed2 <= fixed3;
    bool equal = fixed2 == fixed3;
    bool notEqual = fixed2 != fixed3;

    std::cout << "fixed2 > fixed3: " << greaterThan << std::endl;
    std::cout << "fixed2 < fixed3: " << lessThan << std::endl;
    std::cout << "fixed2 >= fixed3: " << greaterThanOrEqual << std::endl;
    std::cout << "fixed2 <= fixed3: " << lessThanOrEqual << std::endl;
    std::cout << "fixed2 == fixed3: " << equal << std::endl;
    std::cout << "fixed2 != fixed3: " << notEqual << std::endl;

    // Test arithmetic operators
    Fixed sum = fixed2 + fixed3;
    Fixed difference = fixed2 - fixed3;
    Fixed product = fixed2 * fixed3;
    Fixed quotient = fixed2 / fixed3;

    std::cout << "fixed2 + fixed3: " << sum << std::endl;
    std::cout << "fixed2 - fixed3: " << difference << std::endl;
    std::cout << "fixed2 * fixed3: " << product << std::endl;
    std::cout << "fixed2 / fixed3: " << quotient << std::endl;

    // Test pre-increment and post-increment operators
    Fixed preIncrement = ++fixed2;
    Fixed postIncrement = fixed2++;

    std::cout << "++fixed2: " << preIncrement << std::endl;
    std::cout << "fixed2++: " << postIncrement << std::endl;

    // Test pre-decrement and post-decrement operators
    Fixed preDecrement = --fixed2;
    Fixed postDecrement = fixed2--;

    std::cout << "--fixed2: " << preDecrement << std::endl;
    std::cout << "fixed2--: " << postDecrement << std::endl;

    // Test min and max functions
    Fixed a(10);
    Fixed b(20);
    std::cout << "max(a, b): " << Fixed::min(a, b) << std::endl; 
    std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl; 

    // Test getRawBits and setRawBits functions
    int rawBits = fixed2.getRawBits();
    std::cout << "fixed2 raw bits: " << rawBits << std::endl;
    intValue = fixed2.toInt();
    std::cout << "fixed2 to int: " << intValue << std::endl;

    fixed2.setRawBits(123);
    std::cout << "fixed2 raw bits after setRawBits(123): " << fixed2.getRawBits() << std::endl;
    intValue = fixed2.toInt();
    std::cout << "fixed2 to int: " << intValue << std::endl;


    return 0;
}