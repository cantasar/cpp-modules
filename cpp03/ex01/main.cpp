#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ScavTrap	scav("scav");

	scav.attack("scav1");
	scav.attack("scav2");
	scav.takeDamage(3);
	scav.takeDamage(14);
	scav.beRepaired(10);
	scav.attack("scav3");
	scav.takeDamage(12);
	scav.takeDamage(52);

	scav.guardGate();
}
