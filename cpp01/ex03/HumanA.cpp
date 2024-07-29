#include "HumanA.hpp"

HumanA::HumanA(const std::string name, Weapon &weapon) : weaponA(weapon) 
{
    this->name = name;
}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << weaponA.getType() << std::endl;
}
