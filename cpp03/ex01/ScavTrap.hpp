#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(string name);
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(const ScavTrap &other);
		~ScavTrap();

		void attack(const string &target);
		void guardGate();
};


#endif