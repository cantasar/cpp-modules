#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    FragTrap frag("frag");

    frag.attack("frag1");
    frag.beRepaired(200);
	frag.takeDamage(30);
    frag.highFivesGuys();

    return (0);
}
