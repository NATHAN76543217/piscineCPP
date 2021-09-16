#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat bob("bob", 100);

	std::cout << bob << std::endl;

	bob.promote();
	bob.promote();
	bob.retrograde();
	std::cout << bob << std::endl << std::endl;

	std::cout << "--creating Ann--" << std::endl;
	try {
		Bureaucrat ann("Ann", 1000);
	}
	catch(std::exception & e)
	{
		std::cout << "Yeah I catched it!" << std::endl;
		std::cout << "- " << e.what() << std::endl;
	}
	std::cout << std::endl << "--creating Mike--" << std::endl;
	try {
		Bureaucrat ann("Mike", 0);
	}
	catch(std::exception & e)
	{
		std::cout << "Yeah I catched it!" << std::endl;
		std::cout << "- " << e.what() << std::endl;
	}
	std::cout << std::endl << "--creating Mina--" << std::endl;
	Bureaucrat *mina = new Bureaucrat("Mina", 2);
	try {
		mina->promote();
		std::cout << *mina << std::endl;
		mina->promote();
		std::cout << *mina << std::endl;
		mina->setGrade(150);
		std::cout << *mina << std::endl;
		mina->setGrade(0);

	}
	catch(std::exception & e)
	{
		std::cout << "Yeah I catched it!" << std::endl;
		std::cout << "- " << e.what() << std::endl;
	}
	std::cout << std::endl << "--Deleting mina--" << std::endl;
	delete mina;
	std::cout << std::endl << "And say goodbye to bob:" << std::endl;

	return 0;
}