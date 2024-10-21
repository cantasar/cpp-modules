#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	cout << "Cat default constructor called" << endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat &other) {
	cout << "Cat copy constructor called" << endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other) {
	cout << "Cat assignation operator called" << endl;
    type = other.type;
    delete brain;
    brain = new Brain();
    brain = other.brain;
    return *this;
}

Cat::~Cat() {
	cout << "Cat destructor called" << endl;
	delete this->brain;
}

void Cat::makeSound() const {
	cout << "Meow Meow" << endl;
}
