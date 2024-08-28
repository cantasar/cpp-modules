#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    this->name = "no name";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(string name) {
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	cout << "ScavTrap Constructor Called" << endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) {
	cout << "ScavTrap Copy Constructor Called" << endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	cout << "ScavTrap Assignment operator called" << endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return *this;
}

ScavTrap::~ScavTrap() {
	cout << "ScavTrap Destructor Called" << endl;
}

void ScavTrap::attack(const string &target) {
	if (this->hitPoints > 0 && this->energyPoints > 0) {
		cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << endl;
		this->energyPoints -= 1;
	} else if (this->hitPoints <= 0) {
		cout << "ScavTrap " << this->name << " is dead and cannot attack" << endl;
		return;
	} else if (this->energyPoints <= 0) {
		cout << "ScavTrap " << this->name << " is out of energy and cannot attack" << endl;
		return;
	}
}

void ScavTrap::guardGate() {
	cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << endl;
}