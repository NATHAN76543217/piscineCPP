#include "Character.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    AMateria        *tmp;
    IMateriaSource  *src = new MateriaSource();
    ICharacter      *me = new Character("me");
    ICharacter		*bob = new Character("bob");

	std::cout << std::endl << "--Learn ICE--" << std::endl;
	tmp = new Ice();
    src->learnMateria(tmp);
	
	std::cout << "--Deleting ICE" << std::endl; 
	delete tmp;

	std::cout << std::endl << "--Learn CURE--" << std::endl;
	tmp = new Cure();
    src->learnMateria(tmp);
	std::cout << std::endl << "--Deleting CURE" << std::endl; 
	delete tmp;

	std::cout << std::endl << "--Create and equip ICE--" << std::endl;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);

	std::cout << std::endl << "--Create and equip CURE--" << std::endl;
    tmp = src->createMateria("cure");
    me->equip(tmp);

	std::cout << *(Character*)me << std::endl;
	std::cout << std::endl << "--Using skills--" << std::endl;
    me->use(-1, *bob);
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    me->use(4, *bob);
	std::cout << std::endl << "--Unequip materia--" << std::endl;
	me->unequip(0);
	me->unequip(0);
	std::cout << std::endl << "--Deleting characters" << std::endl; 
    delete bob;
    delete me;
	std::cout << std::endl << "--Deleting MateriaSource" << std::endl; 
    delete src;
    return 0;
}