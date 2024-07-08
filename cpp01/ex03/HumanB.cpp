#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
}

HumanB::HumanB(std::string name, Weapon &weapon)
{
	this->name = name;
	this->weaponB = &weapon;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weaponB = &weapon;
}

void HumanB::attack()
{
	std::cout << this->name << " attacks with their " << weaponB->getType() << std::endl;
}

HumanB::~HumanB()
{
}
