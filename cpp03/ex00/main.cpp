#include "ClapTrap.hpp"

int main() {
	ClapTrap	clap("clap");

	clap.attack("clap1");
	clap.attack("clap2");
	clap.takeDamage(3);
	clap.beRepaired(10);
	clap.attack("clap3");
	clap.takeDamage(10);
	clap.takeDamage(10);
	clap.takeDamage(10);
	clap.takeDamage(10);

	return 0;
}