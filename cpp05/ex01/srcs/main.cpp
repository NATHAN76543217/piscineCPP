#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	bob("bob", 100);
	Form		f1();
	std::cout << bob << std::endl;

	return 0;
}