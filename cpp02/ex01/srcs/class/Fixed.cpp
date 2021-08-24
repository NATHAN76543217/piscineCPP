#include "Fixed.hpp"

/*
** ------------------------------- GLOBALS --------------------------------
*/

const int Fixed::_fpart = 8;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
	this->_value <<= this->_fpart;
}

Fixed::Fixed( const Fixed & src )
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = src.getRawBits();
}

Fixed::Fixed(const int value) : _value(value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value <<= this->_fpart;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called " << std::endl;
	this->_value = (int)std::roundf(value * (1 << this->_fpart)); 
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

Fixed &		Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Assignation operator called" << std::endl;
	if ( this != &rhs )
	{
		this->_value = rhs.getRawBits();
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

int		Fixed::toInt( void ) const
{
	return this->_value >> 8;
}

float		Fixed::toFloat( void ) const
{
	return this->_value / (float)(1 << this->_fpart);
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void	Fixed::setRawBits(int const value)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = value;
	return ;
}

/* ************************************************************************** */