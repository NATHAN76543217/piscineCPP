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
	uint i;
	for (i = 0; i < this->nbRequestKnow; i++)
	{
		if (this->knowRequestName[i] == formName)
			break ;
	}
	switch (i)
	{
		case 0:
			return new RobotomyRequestForm(target);
		case 1:
			return new PresidentialPardonForm(target);
		case 2:
			return new ShrubberyCreationForm(target);
		default:
			throw Intern::unknowFormRequest();
	}
	return NULL;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */