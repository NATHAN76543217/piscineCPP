#include "Bureaucrat.hpp"
# include "Intern.hpp"

int	main()
{
	const std::string requests[3] = {
			"robotomy request",
			"presidential pardon",
			"shrubbery creation"
		};
	Bureaucrat	k("bg", 1);
	Intern		someRandomIntern;
	Form 		*rrf;

	std::cout << std::endl << "--use Forms created by an Intern--" << std::endl;
	for (uint i = 0; i < 3; i++)
	{
		rrf = someRandomIntern.makeForm(requests[i], "bender");
		k.signForm(*rrf);
		k.executeForm(*rrf);
		delete rrf;
		std::cout << std::endl << std::endl;
	}
	try {
		rrf = someRandomIntern.makeForm("some error", "bender");
	}
	catch (std::exception const & e)
	{
		std::cout << "Form creation failed because: " << e.what() << std::endl;
	}
	return 0;
}