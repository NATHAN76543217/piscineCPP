#include "Annuaire.hpp"
#include <iostream>

int main()
{
	Annuaire    nul;

	nul.displayCommands();
	while (nul.isOpen())
		nul.command(nul.askInput());

	return 0;
}