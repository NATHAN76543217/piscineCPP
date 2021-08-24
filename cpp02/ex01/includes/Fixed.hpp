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
		
		void	setRawBits( int const value );
		int		getRawBits( void ) const;
		int		toInt( void ) const;
		float	toFloat( void ) const;

	private:
		int					_value;
		static const int	_fpart;

};
std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif /* *********************************************************** FIXED_H */