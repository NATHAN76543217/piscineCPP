#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	bob("bob", 100);
	Form		f1;
	Form		f2("Beauty", 10, 20);
	Form		f3("Good", 120, 150);

	std::cout << std::endl << "---announce---" << std::endl;

	std::cout << bob << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << f3 << std::endl;

	std::cout << std::endl << "---exceptions---" << std::endl;

	try
	{
		Form		f4("Bad", 0, 120);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form		f5("Bad", 30, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "---sign---" << std::endl;
	bob.signForm(f2);	
	bob.signForm(f3);
	bob.signForm(f3);

	std::cout << std::endl << "---test copy/assign---" << std::endl;
	Form f6(f3);
	std::cout << f6 << std::endl;
	Form f7;
	f7 = f6;
	std::cout << f7 << std::endl;
	return 0;
}