#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{

	public:

		Fixed();
		Fixed( Fixed const & src );
		Fixed(const int value);
		Fixed(const float value);

		~Fixed();

		Fixed &		operator=( Fixed const & rhs );
		Fixed		operator+( Fixed const & rhs ) const;
		Fixed &		operator+=( Fixed const & rhs );
		Fixed		operator-( Fixed const & rhs ) const;
		Fixed &		operator-=( Fixed const & rhs );
		Fixed		operator*( Fixed const & rhs ) const;
		Fixed &		operator*=( Fixed const & rhs );
		Fixed		operator/( Fixed const & rhs ) const;
		Fixed &		operator/=( Fixed const & rhs );
		bool		operator<(Fixed const & rhs) const;
		bool		operator>(Fixed const & rhs) const;
		bool		operator<=(Fixed const & rhs) const;
		bool		operator>=(Fixed const & rhs) const;
		bool		operator==(Fixed const & rhs) const;
		bool		operator!=(Fixed const & rhs) const;
		Fixed		&operator++();
		Fixed		operator++(int);
		Fixed		&operator--();
		Fixed		operator--(int);

		void	setRawBits( int const value );
		int		getRawBits( void ) const;
		float	getEpsilon( void ) const;
		float	getRawEpsilon( void ) const;
		int		toInt( void ) const;
		float	toFloat( void ) const;

		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed const	&min(Fixed const &a, Fixed const &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static Fixed const	&max(Fixed const &a, Fixed const &b);
	private:
		int					_value;
		static const int	_fpart;
		static const float	_e;

};
std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif /* *********************************************************** FIXED_H */