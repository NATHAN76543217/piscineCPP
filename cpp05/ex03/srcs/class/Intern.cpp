#include "Intern.hpp"

/*
** ------------------------------- STATICS --------------------------------
*/

const uint			Intern::nbRequestKnow = 3;
const std::string	Intern::knowRequestName[3] = {
	"robotomy request",
	"presidential pardon",
	"shrubbery creation"
};

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern( const Intern & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	if ( this != &rhs )
	{
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Intern const & i )
{
	(void)i;
	o << "Some random intern..." ;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

Form*			Intern::makeForm(std::string formName, std::string target) const 
	throw(Intern::unknowFormRequest)
{
	uint	i;
	Form	*form = NULL;

	for (i = 0; i < this->nbRequestKnow; i++)
	{
		if (this->knowRequestName[i] == formName)
			break ;
	}
	switch (i)
	{
		case 0:
			form = new RobotomyRequestForm(target);
			break ;
		case 1:
			form = new PresidentialPardonForm(target);
			break ;
		case 2:
			form = new ShrubberyCreationForm(target);
			break ;
		default:
			throw Intern::unknowFormRequest();
	}
	std::cout << "Intern creates an " << formName << " form." << std::endl;
	return form;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */