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

		Fixed		operator+( Fixed const & rhs ) const;
		Fixed		operator-( Fixed const & rhs ) const;
		Fixed		operator*( Fixed const & rhs ) const;
		Fixed		operator/( Fixed const & rhs ) const;
		Fixed		operator++( void );
		Fixed		operator--( void );
		Fixed		operator++( int );
		Fixed		operator--( int );

		float		toFloat( void ) const;
		int			toInt( void ) const;
		int			getRawBits( void ) const;
		void		setRawBits( int const raw );

		static float		getEpsilon( void );
		static float		getEpsilonSquare( void );
		static Fixed		&min(Fixed  & lhs, Fixed  & rhs);
		static Fixed		&max(Fixed  & lhs, Fixed  & rhs);
		static Fixed const	&min(Fixed const & lhs, Fixed const & rhs);
		static Fixed const	&max(Fixed const & lhs, Fixed const & rhs);

	private:
		int					_value;
	
		static const int	_floatingPart;
		static const float	_e;
		static const float	_eSquare;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);
bool			operator!=(Fixed const &lhs, Fixed const & rhs);
bool			operator==(Fixed const &lhs, Fixed const & rhs);
bool			operator<=(Fixed const &lhs, Fixed const & rhs);
bool			operator>=(Fixed const &lhs, Fixed const & rhs);
bool			operator<(Fixed const &lhs, Fixed const & rhs);
bool			operator>(Fixed const &lhs, Fixed const & rhs);

#endif /* *********************************************************** FIXED_H */