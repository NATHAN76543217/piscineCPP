#include "Bureaucrat.hpp"

/*
** --------------------------------- STATICS ----------------------------------
*/

const	uint		Bureaucrat::gradeMax = 1;
const	uint		Bureaucrat::gradeMin = 150;
const	std::string Bureaucrat::defaultName = "default";

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : _name(Bureaucrat::defaultName), _grade(Bureaucrat::gradeMin)
{
	std::cout << "Create a Bureaucrat of level " << this->_grade << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, uint grade) 
	throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException ) : _name(name)
{
	this->setGrade(grade);
	std::cout << "Create a Bureaucrat of level " << this->_grade << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) : _name(src._name)
{
	this->setGrade(src._grade);
	std::cout << "Create a Bureaucrat of level " << this->_grade << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & B )
{
	o << B.getName() << ", Bureaucrat grade " << B.getGrade() << ".";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void			Bureaucrat::signForm( Form & f) const
{
	if (f.isSigned())
	{
		std::cout << this->_name << " cannot signs " << f.getName() << " because \"This form is already signed\"." << std::endl;
		return ;
	}
	try
	{
		f.beSigned(*this);
		std::cout << this->_name << " signs " << f.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->_name << " cannot signs " << f.getName() << " because \"" << e.what() << "\"." << std::endl;
	}
}

void			Bureaucrat::retrograde( void )
{
	if ( this->_grade < Bureaucrat::gradeMin )
		this->_grade++;
}

void			Bureaucrat::promote( void )
{
	if ( this->_grade > Bureaucrat::gradeMax )
		this->_grade--;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	const &		Bureaucrat::getName( void ) const
{
	return this->_name;
}

uint					Bureaucrat::getGrade( void ) const
{
	return this->_grade;
}

void		Bureaucrat::setGrade( uint const grade ) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException)
{
		if (grade < Bureaucrat::gradeMax)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > Bureaucrat::gradeMin)
			throw Bureaucrat::GradeTooLowException();
		this->_grade = grade;
}


/* ************************************************************************** */