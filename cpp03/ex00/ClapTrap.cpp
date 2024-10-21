#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	this->name = "(no name)";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	cout << "Default constructor called" << endl;
}

ClapTrap::ClapTrap(string _name) {
	this->name = _name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	cout << "Constructor called: " << this->name << endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	*this = other;
	cout << "Copy constructor called: " << this->name << endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	cout << "Assignation operator called: " << other.name << "->" << this->name << endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return *this;
}

ClapTrap::~ClapTrap() {
	cout << "Destructor called: " << this->name << endl;
}


void ClapTrap::attack(const string &target) {
	if (this->hitPoints > 0 && this->energyPoints > 0) {
		cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << endl;
		this->energyPoints -= 1;
	} else if (this->hitPoints <= 0) {
		cout << "ClapTrap " << this->name << " is dead and cannot attack" << endl;
		return;
	} else if (this->energyPoints <= 0) {
		cout << "ClapTrap " << this->name << " is out of energy and cannot attack" << endl;
		return;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints > 0 && this->energyPoints > 0) {
		cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << endl;
		this->hitPoints -= amount;
		if (this->hitPoints <= 0) {
			cout << "ClapTrap " << this->name << " is dead" << endl;
		}else
			cout << "ClapTrap " << this->name << " hit points left: " << this->hitPoints << endl;
	} else {
		cout << "ClapTrap " << this->name << " is already dead" << endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->hitPoints > 0 && this->energyPoints > 0) {
		cout << "ClapTrap " << this->name << " is repaired for " << amount << " points!" << endl;
		this->hitPoints += amount;
		this->energyPoints--;
	} else {
		cout << "ClapTrap " << this->name << " is dead and cannot be repaired" << endl;
	}
}
