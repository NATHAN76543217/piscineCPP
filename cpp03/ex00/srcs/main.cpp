#include "ClapTrap.hpp"

int main()
{
	std::string	target("default ClapTrap");
	ClapTrap	clap;
	ClapTrap	clip("Joe");

	std::cout << clap << std::endl;
	std::cout << clip << std::endl;
	clip.attack(target);
	clap.takeDamage(clip.getAttack());
	clip.beRepaired(5);
	return 0;
}