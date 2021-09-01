#include "FragTrap.hpp"

int main()
{
	FragTrap frag("Jack");
	FragTrap joe(frag);
	ClapTrap clap("Jane");

	std::cout << std::endl;
	joe.setName("Joe");
	std::cout << clap << std::endl;
	std::cout << frag << std::endl;
	std::cout << joe << std::endl;

	frag.highFivesGuys();
	joe.highFivesGuys();
	std::cout << std::endl;

	joe.attack(frag.getName());
	frag.takeDamage(joe.getAttack());

	std::cout << frag << std::endl << std::endl;
	return 0;
}