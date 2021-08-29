#include "Point.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Point::Point() : _x(0), _y(0)
{
}

Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y)
{

}

Point::Point( Point const & src ) : _x(src._x), _y(src._y)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Point::~Point()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Point &				Point::operator=( Point const & rhs )
{
	if ( this != &rhs )
	{
		this->_x = rhs._x;
		this->_y = rhs._y;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Point const & point )
{
	o << "(" << point.getAbs() << ", " << point.getOrd() << ")";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

Fixed	Point::distance(Fixed & point)
{
 return point;	
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Fixed	Point::getAbs( void ) const
{
	return this->_x;
}

Fixed	Point::getOrd( void ) const
{
	return this->_y;
}

/* ************************************************************************** */