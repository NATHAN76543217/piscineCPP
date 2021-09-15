#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span() : _limit(0) 
{
}

Span::Span( uint N ) : _limit(N)
{
}

Span::Span( std::vector<int>::const_iterator start, std::vector<int>::const_iterator end ) : _limit(std::distance(start, end))
{
	this->_values = std::vector<int>(start, end);
}

Span::Span( const Span & src )
{
	this->_values = src._values;
	this->_limit = src._limit;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		this->_values = rhs._values;
		this->_limit = rhs._limit;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Span const & i )
{
	o << "Span: {" << std::endl;
	o << "size: " << i.getSize();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
bool		Span::spannable( void ) const
{
	if (this->_values.size() > 1)
		return true;
	return false;
}

void		Span::addNumber(int number)
{
	if (this->_values.size() >= this->_limit )
		throw Span::SpanFullException();
	this->_values.push_back(number); 
}

int		Span::shortestSpan( void )
{
	if (!this->spannable())
		throw NotSpannableException();
	int last = INT32_MAX;
	std::sort(this->_values.begin(), this->_values.end());
	for (std::vector<int>::iterator it = this->_values.begin(); it != this->_values.end() - 1; it++)
	{
		int tmp = std::abs(*it - *(it + 1));
		if (tmp < last)
			last = tmp;
	}
	return last;
}

int		Span::longestSpan( void )
{
	if (!this->spannable())
		throw NotSpannableException();
	std::sort(this->_values.begin(), this->_values.end());
	return std::abs(this->_values.front() - this->_values.back());
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

uint		Span::getSize( void ) const
{
	return this->_values.size();
}

/* ************************************************************************** */