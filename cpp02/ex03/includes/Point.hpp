#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <string>
# include "Fixed.hpp"

class Point
{

	public:

		Point();
		Point(Fixed const x, Fixed const y);
		Point( Point const & src );
		~Point();

		Point &		operator=( Point const & rhs );

		Fixed getAbs( void ) const;
		Fixed getOrd( void ) const;
		Fixed distance(Fixed & fixed);


	private:
		Fixed _x;
		Fixed _y;
		// Fixed const _x;
		// Fixed const _y;
};

std::ostream &			operator<<( std::ostream & o, Point const & i );

#endif /* *********************************************************** POINT_H */