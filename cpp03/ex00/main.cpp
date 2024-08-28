#include "ClapTrap.hpp"
#include <iostream>

int main() {
	ClapTrap	Jack("Jack");
	
	std::cout << "\n---Start attacking---\n" << std::endl;

	Jack.attack("Sharks");
	Jack.attack("Pirates");
	Jack.takeDamage(3);
	Jack.beRepaired(10);
	Jack.attack("Dragon");
	Jack.attack("Spirits");
	Jack.attack("Lions");
	Jack.attack("Kings");
	Jack.takeDamage(10);
	Jack.takeDamage(10);
	Jack.takeDamage(10);
	Jack.takeDamage(10);

	std::cout << "\nFights are over..." << std::endl;
	return 0;
}
