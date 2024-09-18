#include "Brain.hpp"

Brain::Brain() {
	cout << "Brain default constructor called" << endl;
}

Brain::Brain(const Brain &other) {
	cout << "Brain copy constructor called" << endl;
	*this = other;
}

Brain &Brain::operator=(const Brain &other) {
	cout << "Brain assignation operator called" << endl;
	if (this != &other)
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	return *this;
}

Brain::~Brain() {
	cout << "Brain destructor called" << endl;
}
