#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : Form()
{
	std::cout << "ShrubberyCreationForm default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137)
{
	this->setTarget(target);
	std::cout << "ShrubberyCreationForm constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : Form(src)
{
	std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
	{
		Form::operator=(rhs);
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
	o << (Form)i;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void			ShrubberyCreationForm::execute(bureaucrat const & B) const
{
	
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */