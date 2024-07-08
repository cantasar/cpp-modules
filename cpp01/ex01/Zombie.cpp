#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->name = "";
}
void Zombie::setname(std::string name)
{
	this->name = name;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << " is died" << std::endl;
}