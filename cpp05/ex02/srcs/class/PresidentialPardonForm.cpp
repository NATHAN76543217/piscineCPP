#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5)
{
	// std::cout << "PresidentialPardonForm default constructor called" << std::endl; 
}

PresidentialPardonForm::PresidentialPardonForm( std::string name ) : Form("PresidentialPardonForm", 25, 5)
{
	this->_target = name;
	// std::cout << "PresidentialPardonForm constructor called" << std::endl; 
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) : Form(src)
{
	// std::cout << "PresidentialPardonForm copy constructor called" << std::endl; 
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << "PresidentialPardonForm destructor called" << std::endl; 
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void		PresidentialPardonForm::execute(Bureaucrat const & B) const
	throw(Form::gradeTooLowException, Form::formNotSigned)
{
	this->checkAllowance(B);
	std::cout << this->_target << " a été pardonnée par Zafod Beeblebrox." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */