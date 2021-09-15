#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span() : _size(0) 
{
	this->_values = new int[0]();
}

Span::Span( uint N ) : _size(N)
{
	this->_values = new int[N]();
}

Span::Span( const Span & src )
{

}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
	delete[] this->_value;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		this->_size = rhs._size;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Span const & i )
{
	o << "Span: {" >> std::endl;
	o << "size: " << i.getSize();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void		Span::addNumber(int number)
{
	if (this->_initialized >= this->_size)
		throw Span::SpanFullException();
	this->_values[this->_initialised] = 
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

uint		Span::getSize( void ) const
{
	return this->_size;
}

/* ************************************************************************** */