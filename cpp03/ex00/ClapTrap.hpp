#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
using std::string;
using std::cout;
using std::endl;

class ClapTrap {
	private:
		string name;
		int hitPoints;
		int energyPoints;
		int attackDamage;
	public:
		ClapTrap();
		ClapTrap(string name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();

		void attack(const string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};

#endif