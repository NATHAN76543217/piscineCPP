#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form()
{
}

Form::Form( const Form & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

// Form &				Form::operator=( Form const & rhs )
// {
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	// return *this;
// }

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << "FORM " << i.getName() << std::endl;
	o << "signed: " << i.signed() << std::endl;
	o << "Signing grade: " << i.getSigningGrade() << std::endl;
	o << "Executing grade: " << i.getExecutingGrade() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

uint				Form::getSigningGrade( void ) const
{
	return this->_signing_grade;
}

uint				Form::getExecutingGrade( void ) const
{
	return this->_executing_grade;
}

bool				Form::isSigned( void ) const
{
	return this->_signed;
}

/* ************************************************************************** */