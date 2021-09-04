#include "AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AMateria::AMateria( std::string const & type ) : _type(type)
{
	std::cout << "AMateria type constructor called" << std::endl;
}

AMateria::AMateria( const AMateria & src ) : _type(src._type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AMateria &				AMateria::operator=( AMateria const & rhs )
{
	if ( this != &rhs )
	{
		// this->_type = rhs.getValue();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AMateria const & i )
{
	o << "AMateria of type: " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void		AMateria::use(ICharacter& target)
{
	std::cout << "use " << this->_type << " on " << target.getName() << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string const & AMateria::getType( void ) const
{
	return this->_type;
}

/* ************************************************************************** */