#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	type = "WrongAnimal";
	cout << "WrongAnimal default constructor called" << endl;
}

WrongAnimal::WrongAnimal(string type) {
	this->type = type;
	cout << "WrongAnimal type constructor called" << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	cout << "WrongAnimal copy constructor called" << endl;
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	cout << "WrongAnimal assignation operator called" << endl;
	if (this != &other)
		type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	cout << "WrongAnimal destructor called" << endl;
}

string WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::makeSound() const {
	cout << "WrongAnimal sound" << endl;
}
