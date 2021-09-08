#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap diam("Jack");
	DiamondTrap diamCpy(diam);
	DiamondTrap diamAssign;
	DiamondTrap other("other");

	std::cout << diamAssign << std::endl;
	diamAssign = diamCpy;
	diamAssign.setName("Assign");
	diamCpy.setName("Joe");
	std::cout << diam << std::endl;
	std::cout << diamCpy << std::endl;
	std::cout << diamAssign << std::endl;
	std::cout << other << std::endl;

	std::cout << std::endl << "--Diamond function--" << std::endl;
	other.whoAmI();

	std::cout << std::endl << "--basic functions--" << std::endl;
	diamCpy.attack(other);
	diamAssign.beRepaired(diamCpy.getAttack());

	std::cout << std::endl << "--Special functions--" << std::endl;
	other.highFivesGuys();
	other.guardGate();

	std::cout << std::endl << other << std::endl;
	std::cout << diamAssign << std::endl;
	return 0;
}