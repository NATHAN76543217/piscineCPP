#include "Form.hpp"

/*
** ------------------------------- STATIC --------------------------------
*/

const	uint		Form::gradeMax = 1;
const	uint		Form::gradeMin = 150;
const	std::string Form::defaultName = "default";

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : 
	_name(Form::defaultName),
	_signed(false),
	_signing_grade(Bureaucrat::gradeMin),
	_executing_grade(Bureaucrat::gradeMin),
	_target(Form::defaultName)
{
	std::cout << "Form default constructor" << std::endl;
}

Form::Form(std::string name, uint signingGrade, uint executingGrade) : 
	_name(name),
	_signed(false),
	_target(Form::defaultName)
{
	this->setSigningGrade(signingGrade);
	this->setExecutingGrade(executingGrade);
	std::cout << "Form constructor" << std::endl;
}

Form::Form( const Form & src ) : 
	_name(src._name), 
	_signed(src._signed), 
	_signing_grade(src._signing_grade),
	_executing_grade(src._executing_grade),
	_target(src._target)
{
	std::cout << "Form copy constructor" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
	std::cout << "Form destructor" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs._name;
		this->_signed = rhs._signed;
		this->_signing_grade = rhs._signing_grade;
		this->_executing_grade = rhs._executing_grade;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << "name : " << i.getName() << std::endl;
	o << "target: " << i.getTarget() << std::endl;
	o << "signed : " << i.isSigned() << std::endl;
	o << "Signing grade : " << i.getSigningGrade() << std::endl;
	o << "Executing grade : " << i.getExecutingGrade() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void		Form::checkAllowance(Bureaucrat const & B) const 
	throw (Form::gradeTooLowException, Form::formNotSigned)
{
	if ( B.getGrade() > this->_executing_grade )
		throw Form::gradeTooLowException();
	else if (this->_signed == false)
		throw Form::formNotSigned();

}

void		Form::beSigned(Bureaucrat const & B)
	throw (Form::gradeTooLowException, Form::alreadySignedException)
{
	if (B.getGrade() > this->_signing_grade)
		throw Form::gradeTooLowException();
	else if (this->_signed)
		throw Form::alreadySignedException();
	else
		this->_signed = true;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

bool				Form::isSigned( void ) const
{
	return this->_signed;
}

std::string			Form::getName( void ) const
{
	return this->_name;
}

uint				Form::getSigningGrade( void ) const
{
	return this->_signing_grade;
}

uint				Form::getExecutingGrade( void ) const
{
	return this->_executing_grade;
}

std::string			Form::getTarget( void ) const
{
	return this->_target;
}

void				Form::setSigningGrade(uint signingGrade)
	throw(Form::gradeTooHighException, Form::gradeTooLowException)
{
	if (signingGrade < Form::gradeMax)
		throw Form::gradeTooHighException();
	else if (signingGrade > Form::gradeMin)
		throw Form::gradeTooLowException();
	this->_signing_grade = signingGrade;
}

void				Form::setExecutingGrade(uint executingGrade)
	throw(Form::gradeTooHighException, Form::gradeTooLowException)
{
	if (executingGrade < Form::gradeMax)
		throw Form::gradeTooHighException();
	else if (executingGrade > Form::gradeMin)
		throw Form::gradeTooLowException();
	this->_executing_grade = executingGrade;
}

void				Form::setTarget(std::string str)
{
	this->_target = str;
}

/* ************************************************************************** */