#include "Fixed.hpp"

/*
** ------------------------------- GLOBALS --------------------------------
*/

const int Fixed::_fpart = 8;
const float Fixed::_e = 1 / (float) (1 << Fixed::_fpart);

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : _value(0)
{
	this->_value <<= this->_fpart;
}

Fixed::Fixed( const Fixed & src )
{
	this->_value = src.getRawBits();
}

Fixed::Fixed(const int value) : _value(value)
{
	this->_value <<= this->_fpart;
}

Fixed::Fixed(const float value)
{
	this->_value = (int)std::roundf(value * (1 << this->_fpart)); 
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

Fixed &		Fixed::operator=( Fixed const & rhs )
{
	// std::cout << "Assignation operator called" << std::endl;
	if ( this != &rhs )
	{
		this->_value = rhs.getRawBits();
	}
	return *this;
}

Fixed		Fixed::operator+( Fixed const & rhs ) const
{
	// std::cout << "Addition operator called" << std::endl;
	Fixed res;
	res.setRawBits(this->_value + rhs.getRawBits());
	return res;
}

Fixed &		Fixed::operator+=( Fixed const & rhs )
{
	// std::cout << "Assignation operator called" << std::endl;
	this->_value += rhs.getRawBits();
	return *this;
}

Fixed		Fixed::operator-( Fixed const & rhs ) const
{
	// std::cout << "Substraction operator called" << std::endl;
	Fixed res;
	res.setRawBits(this->_value - rhs.getRawBits());
	return res;
}

Fixed &		Fixed::operator-=( Fixed const & rhs )
{
	// std::cout << "Assignation operator called" << std::endl;
	this->_value -= rhs.getRawBits();
	return *this;
}

Fixed		Fixed::operator*( Fixed const & other ) const
{
	// std::cout << "Multiplication: " << this->_value << " " << other.getRawBits() << std::endl;
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed &		Fixed::operator*=( Fixed const & other )
{
	// std::cout << "Assignation operator called" << std::endl;
	this->_value = (int)std::roundf((this->toFloat() * other.toFloat()) * (1 << this->_fpart)); 
	return *this;
}

Fixed		Fixed::operator/( Fixed const & rhs ) const
{
	// std::cout << "Division operator called" << std::endl;
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &		Fixed::operator/=( Fixed const & rhs )
{
	// std::cout << "Assignation operator called" << std::endl;
	this->_value = (int)std::roundf((this->toFloat() / rhs.toFloat()) * (1 << this->_fpart)); 
	return *this;
}

bool		Fixed::operator<(Fixed const & rhs) const
{
	return this->_value < rhs.getRawBits();
}

bool		Fixed::operator>(Fixed const & rhs) const
{
	return (this->_value > rhs.getRawBits());
}

bool		Fixed::operator<=(Fixed const & rhs) const
{
	return this->_value <= rhs.getRawBits();
}

bool		Fixed::operator>=(Fixed const & rhs) const
{
	return (this->_value >= rhs.getRawBits());
}

bool		Fixed::operator==(Fixed const & rhs) const
{
	return this->_value == rhs.getRawBits();
}

bool		Fixed::operator!=(Fixed const & rhs) const
{
	return (this->_value != rhs.getRawBits());
}

// overloaded prefix ++ operator
Fixed		&Fixed::operator++()
{
	this->_value++;
	return *this;
}

// overloaded postfix ++ operator
Fixed		Fixed::operator++(int)
{
	Fixed old(this->toFloat());
	this->_value++;
	return old;
}

// overloaded prefix -- operator
Fixed		&Fixed::operator--()
{
	this->_value--;
	return *this;
}

// overloaded postfix -- operator
Fixed		Fixed::operator--(int)
{
	Fixed old(this->toFloat());
	this->_value--;
	return old;
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

Fixed		&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed		&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return a;
	return b;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int		Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void	Fixed::setRawBits(int const value)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_value = value;
	return ;
}

float	Fixed::getEpsilon(void) const
{
	return this->_e;
}

/* ************************************************************************** */