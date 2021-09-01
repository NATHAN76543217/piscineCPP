#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap diam("Jack");
	DiamondTrap diamCpy(diam);
	DiamondTrap diamAss;
	DiamondTrap other("other");

	std::cout << diamAss << std::endl;
	diamAss = diamCpy;
	diamAss.setName("ass");
	diamCpy.setName("Joe");
	std::cout << diam << std::endl;
	std::cout << diamCpy << std::endl;
	std::cout << diamAss << std::endl;
	std::cout << other << std::endl;

	std::cout << std::endl << "Diamond functions" << std::endl;
	other.whoAmI();

	std::cout << std::endl << "basic functions" << std::endl;
	diamCpy.attack(other);
	diamAss.beRepaired(diamCpy.getAttack());

	std::cout << std::endl << "Special functions" << std::endl;
	other.highFivesGuys();
	other.guardGate();

	std::cout << other << std::endl;
	std::cout << diamAss << std::endl;
	return 0;
}