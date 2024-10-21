#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	cout << "Dog default constructor called" << endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog &other) {
	cout << "Dog copy constructor called" << endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other) {
	cout << "Dog assignation operator called" << endl;
    type = other.type;
    delete brain;
    brain = new Brain();
    brain = other.brain;
    return *this;
}

Dog::~Dog() {
	cout << "Dog destructor called" << endl;
	delete this->brain;
}

void Dog::makeSound() const {
	cout << "Woof Woof" << endl;
}
