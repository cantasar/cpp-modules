#include "FragTrap.hpp"

FragTrap::FragTrap() {
	this->name = "(no name)";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	cout << "FragTrap Default constructor called" << endl;
}

FragTrap::FragTrap(string _name) {
	this->name = _name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	cout << "FragTrap Constructor called" << endl;
}

FragTrap::FragTrap(const FragTrap &other) {
	*this = other;
	cout << "FragTrap Copy constructor called" << endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	cout << "FragTrap Assignment operator called" << endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return *this;
}

FragTrap::~FragTrap() {
	cout << "FragTrap Destructor called" << endl;
}

void FragTrap::highFivesGuys(void) {
	cout << "FragTrap " << this->name << " high fives guys" << endl;
}

