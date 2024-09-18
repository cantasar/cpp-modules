#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
	cout << "WrongCat default constructor called" << endl;
}

WrongCat::WrongCat(const WrongCat &other) {
	cout << "WrongCat copy constructor called" << endl;
	*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	cout << "WrongCat assignation operator called" << endl;
	if (this != &other)
		type = other.type;
	return *this;
}

WrongCat::~WrongCat() {
	cout << "WrongCat destructor called" << endl;
}

void WrongCat::makeSound() const {
	cout << "WrongCat sound" << endl;
}
