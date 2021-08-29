#include "Fixed.hpp"

/*
** ------------------------------- STATIC --------------------------------
*/

const int Fixed::_floatingPart = 8;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << this->_floatingPart;
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = (int) std::roundf(value * (1 << this->_floatingPart));
}

Fixed::Fixed( const Fixed & src ) : _value(src._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &				Fixed::operator=( Fixed const & rhs )
{
	std::cout << "assignation operator called" << std::endl;
	if ( this != &rhs )
	{
		this->_value = rhs.getRawBits();
	}
	return *this;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

int 		Fixed::toInt( void ) const
{
	return this->_value >> this->_floatingPart;
}

float		Fixed::toFloat( void ) const
{
	return this->_value / (float)(1 << this->_floatingPart);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int		Fixed::getRawBits( void ) const 
{
	std::cout << "getRawBits called" << std::endl;
	return this->_value;
} 

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits called" << std::endl;
	this->_value = raw;
}

/* ************************************************************************** */