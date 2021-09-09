#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	Bureaucrat	k("ksos", 145);
	Bureaucrat	bob("bob", 70);
	Bureaucrat	bg("beau gosse", 1);
	RobotomyRequestForm		R1;
	ShrubberyCreationForm	S1("my_beautiful");
	PresidentialPardonForm	P1("this damn brat");

	std::cout << R1 << std::endl;
	std::cout << S1 << std::endl;
	std::cout << P1 << std::endl;

	std::cout << "--- S1 ---" <<std::endl;
	k.signForm(S1);
	k.executeForm(S1);
	
	bg.executeForm(S1);
	std::cout << "--- R1 ---" <<std::endl;

	k.signForm(R1);
	bob.signForm(R1);
	std::cout << std::endl;

	bob.executeForm(R1);
	bg.executeForm(R1);
	std::cout << std::endl << "--- P1 ---" <<std::endl;
	bg.executeForm(P1);
	bg.signForm(P1);
	bg.signForm(P1);
	bg.executeForm(P1);
	std::cout << std::endl << std::endl;

	return 0;
}