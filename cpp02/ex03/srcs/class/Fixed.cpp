#include "Fixed.hpp"

/*
** ------------------------------- STATIC --------------------------------
*/

const int Fixed::_floatingPart = 8;
const float Fixed::_e = 1 << Fixed::_floatingPart;
const float Fixed::_eSquare = (1 / (Fixed::_e * Fixed::_e));

float 	Fixed::getEpsilon()
{
	return 1 / Fixed::_e;
}

float 	Fixed::getEpsilonSquare()
{
	return Fixed::_eSquare;
}

Fixed		&Fixed::min(Fixed & lhs, Fixed & rhs)
{
	if (lhs.getRawBits() < rhs.getRawBits())
		return lhs;
	else
		return rhs;
}

Fixed		&Fixed::max(Fixed & lhs, Fixed & rhs)
{
	if (lhs.getRawBits() > rhs.getRawBits())
		return lhs;
	else
		return rhs;
}

Fixed	const &Fixed::min(Fixed const & lhs, Fixed const & rhs)
{
	if (lhs.getRawBits() < rhs.getRawBits())
		return lhs;
	else
		return rhs;
}

Fixed	const &Fixed::max(Fixed const & lhs, Fixed const & rhs)
{
	if (lhs.getRawBits() > rhs.getRawBits())
		return lhs;
	else
		return rhs;
}


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(int const value)
{
	this->_value = value << this->_floatingPart;
}

Fixed::Fixed(float const value)
{
	this->_value = (int) std::roundf(value * this->_e);
}

Fixed::Fixed( const Fixed & src ) : _value(src._value)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &				Fixed::operator=( Fixed const & rhs )
{
	if ( this != &rhs )
	{
		this->_value = rhs.getRawBits();
	}
	return *this;
}

Fixed				Fixed::operator+( Fixed const & rhs ) const
{
	Fixed f;
	f.setRawBits(this->_value + rhs._value);
	return f;
}

Fixed				Fixed::operator-( Fixed const & rhs ) const
{
	Fixed f;
	f.setRawBits(this->_value - rhs._value);
	return f;
}

Fixed				Fixed::operator*( Fixed const & rhs ) const
{
	Fixed f;
	f.setRawBits((this->_value * rhs._value) >> 8 );
	return f;
}

Fixed				Fixed::operator/( Fixed const & rhs ) const
{
	Fixed f(this->_value / (float) rhs._value);
	return f;
}

Fixed				Fixed::operator++( void )
{
	++this->_value;
	return *this;
}

Fixed				Fixed::operator--( void )
{
	--this->_value;
	return *this;
}

Fixed				Fixed::operator++( int )
{
	Fixed f(this->toFloat());
	++this->_value;
	return f;
}

Fixed				Fixed::operator--( int )
{
	Fixed f(this->toFloat());
	--this->_value;
	return f;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}

bool			operator!=(Fixed const &lhs, Fixed const & rhs)
{
	return lhs.getRawBits() != rhs.getRawBits();
}

bool			operator==(Fixed const &lhs, Fixed const & rhs)
{
	return lhs.getRawBits() == rhs.getRawBits();
}

bool			operator<=(Fixed const &lhs, Fixed const & rhs)
{
	return lhs.getRawBits() <= rhs.getRawBits();
}

bool			operator>=(Fixed const &lhs, Fixed const & rhs)
{
	return lhs.getRawBits() >= rhs.getRawBits();
}

bool			operator<(Fixed const &lhs, Fixed const & rhs)
{
	return lhs.getRawBits() < rhs.getRawBits();
}

bool			operator>(Fixed const &lhs, Fixed const & rhs)
{
	return lhs.getRawBits() > rhs.getRawBits();
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
	return this->_value / (float)Fixed::_e;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int		Fixed::getRawBits( void ) const 
{
	return this->_value;
} 

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

/* ************************************************************************** */