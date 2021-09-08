#include "ScavTrap.hpp"

int main()
{
	std::string target("The Gate Keeper");
	ScavTrap s1;
	ScavTrap scav("Jack");
	ScavTrap joe(scav);
	ClapTrap clap("Jane");

	std::cout << std::endl;
	joe.setName("Joe");
	std::cout << clap << std::endl;
	std::cout << scav << std::endl;
	std::cout << joe << std::endl;

	scav.guardGate();
	joe.attack(target);
	std::cout << std::endl;
	return 0;
}