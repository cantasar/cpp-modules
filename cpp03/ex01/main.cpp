#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
	ScavTrap	scavtrap("A");

	cout << "\nStart attacking...\n" << endl;

	scavtrap.attack("Sharks");
	scavtrap.attack("Pirates");
	scavtrap.takeDamage(3);
	scavtrap.takeDamage(14);
	scavtrap.beRepaired(10);
	scavtrap.attack("Dragon");
	scavtrap.attack("Spirits");
	scavtrap.attack("Lions");
	scavtrap.attack("Kings");

	cout << "\nEnd attacking...\n" << endl;

	scavtrap.guardGate();
}
