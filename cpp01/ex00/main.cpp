#include "Zombie.hpp"
#include <iostream>

int main()
{
	std::cout << "Zombie Created on Stack" << std::endl;
	Zombie zombie1 = Zombie("zombie1");
	zombie1.announce();

	Zombie* zombie2;
	std::cout << "Zombie Created on Heap" << std::endl;
	zombie2 = newZombie("zombie2");
	zombie2->announce();
	delete (zombie2);
	
	return 0;
}
