#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
    FragTrap ft("NARUTO");

    ft.attack("LUFFY");
    ft.beRepaired(200);
    ft.highFivesGuys();
    return (0);
}
