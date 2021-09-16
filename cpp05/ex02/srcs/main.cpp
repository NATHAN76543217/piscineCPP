#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	std::cout << "--create Bureaucrats--" << std::endl;
	Bureaucrat	k("ksos", 145);
	Bureaucrat	bob("bob", 70);
	Bureaucrat	bg("beau gosse", 1);

	std::cout << std::endl << "--create Forms--" << std::endl;
	ShrubberyCreationForm	S1("my_beautiful");
	RobotomyRequestForm		R1;
	PresidentialPardonForm	P1("this damn brat");

	std::cout << std::endl << "--Print Forms--" << std::endl;
	std::cout << R1 << std::endl;
	std::cout << S1 << std::endl;
	std::cout << P1 << std::endl;

	std::cout << "--- S1 ---" <<std::endl;
	k.signForm(S1);
	k.executeForm(S1);
	bg.executeForm(S1);

	std::cout << std::endl << "--- R1 ---" <<std::endl;
	k.signForm(R1);
	bob.signForm(R1);
	bob.executeForm(R1);
	bg.executeForm(R1);
	std::cout << std::endl << "--- P1 ---" <<std::endl;
	bg.executeForm(P1);
	bg.signForm(P1);
	bg.signForm(P1);
	bg.executeForm(P1);
	std::cout << "--- assignation test ---" << std::endl;
	std::cout << R1 << std::endl;
	RobotomyRequestForm	R2;
	R2 = R1;
	R2.setTarget("assigned");
	std::cout << R2 << std::endl;
	return 0;
}