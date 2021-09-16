#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45)
{
	// std::cout << "RobotomyRequestForm default constructor called" << std::endl; 
}

RobotomyRequestForm::RobotomyRequestForm(std::string name) : Form("RobotomyRequestForm", 72, 45)
{
	this->setTarget(name);
	// std::cout << "RobotomyRequestForm constructor called" << std::endl; 
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) : Form(src)
{
	// std::cout << "RobotomyRequestForm copy called" << std::endl; 
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "RobotomyRequestForm destructor called" << std::endl; 
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

/*
** --------------------------------- METHODS ----------------------------------
*/

void		RobotomyRequestForm::execute(Bureaucrat const & B) const
	throw (Form::gradeTooLowException, Form::formNotSigned)
{
	this->checkAllowance(B);
	std::cout << "Brrrrr." << std::endl;
	usleep(500000);
	std::cout << "Drrr." << std::endl;
	usleep(500000);
	std::cout << "Grr." << std::endl;
	usleep(500000);
	std::cout << "Brrrrr." << std::endl;
	usleep(500000);
	if (std::rand() % 2)
	{
		std::cout << "DRRIIIIIINNG." << std::endl;
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	}
	else
	{
		std::cout << "pop." << std::endl;
		std::cout << this->_target << " robotomized" << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */