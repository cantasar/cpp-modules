#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	cout << "Dog default constructor called" << endl;
}

Dog::Dog(const Dog &other) {
	cout << "Dog copy constructor called" << endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other) {
	cout << "Dog assignation operator called" << endl;
	if (this != &other)
		type = other.type;
	return *this;
}

Dog::~Dog() {
	cout << "Dog destructor called" << endl;
}

void Dog::makeSound() const {
	cout << "Woof Woof" << endl;
}

