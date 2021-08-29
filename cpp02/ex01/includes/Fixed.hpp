#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	public:

		Fixed();
		Fixed( int const value );
		Fixed( float const value );
		Fixed( Fixed const & src );
		~Fixed();

		Fixed &		operator=( Fixed const & rhs );

		float		toFloat( void ) const;
		int			toInt( void ) const;
		int			getRawBits( void ) const;
		void		setRawBits( int const raw );

	private:
		int					_value;
		static const int	_floatingPart;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif /* *********************************************************** FIXED_H */