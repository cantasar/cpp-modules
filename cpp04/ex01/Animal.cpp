#include "Animal.hpp"

Animal::Animal() {
	type = "Animal";
	cout << "Animal default constructor called" << endl;
}

Animal::Animal(string type) {
	this->type = type;
	cout << "Animal type constructor called" << endl;
}

Animal::Animal(const Animal &other) {
	cout << "Animal copy constructor called" << endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other) {
	cout << "Animal assignation operator called" << endl;
	if (this != &other)
		type = other.type;
	return *this;
}

Animal::~Animal() {
	cout << "Animal destructor called" << endl;
}

string Animal::getType() const {
	return type;
}

void Animal::makeSound() const {
	cout << "Animal sound" << endl;
}

