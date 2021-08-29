# include <iomanip>
# include "Fixed.hpp"

//TODO fix multiplication and division
int	main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ));
	Fixed const c( 2 );
	Fixed d(20);

	std::cout << std::left << std::setw(9) << "a: " << a << std::endl;
	std::cout << std::left << std::setw(9) << "b: " << b << std::endl;
	std::cout << std::left << std::setw(9) << "c: " << c << std::endl;
	std::cout << std::left << std::setw(9) << "b + c: " << b + c << std::endl;
	std::cout << std::left << std::setw(9) << "a - b: " << a - b << std::endl;
	std::cout << std::left << std::setw(9) << "b * c: " << b * c << std::endl;
	std::cout << std::left << std::setw(9) << "b / c: " << b / c << std::endl;
	std::cout << std::left << std::setw(9) << "b < c: " << (b < c) << std::endl;
	std::cout << std::left << std::setw(9) << "b > c: " << (b > c) << std::endl;
	std::cout << std::left << std::setw(9) << "b <= c: " << (b <= c) << std::endl;
	std::cout << std::left << std::setw(9) << "b >= c: " << (b >= c) << std::endl;
	std::cout << std::left << std::setw(9) << "a >= a: " << (a >= a) << std::endl;
	std::cout << std::left << std::setw(9) << "a == a: " << (a == a) << std::endl;
	std::cout << std::left << std::setw(9) << "a == b: " << (a == b) << std::endl;
	std::cout << std::left << std::setw(9) << "a != a: " << (a != a) << std::endl;
	std::cout << std::left << std::setw(9) << "a != b: " << (a != b) << std::endl;
	std::cout << std::left << std::setw(9) << "epsilon: " << Fixed::getEpsilon() << std::endl;
	std::cout << std::left << std::setw(9) << "++a: " << ++a << std::endl;
	std::cout << std::left << std::setw(9) << "a++: " << a++ << std::endl;
	std::cout << std::left << std::setw(9) << "a: " << a << std::endl;
	std::cout << std::left << std::setw(9) << "--a: " << --a << std::endl;
	std::cout << std::left << std::setw(9) << "a--: " << a-- << std::endl;
	std::cout << std::left << std::setw(9) << "a: " << a << std::endl;
	std::cout << std::left << std::setw(9) << "b: " << b << std::endl;
	std::cout << std::left << std::setw(9) << "c: " << c << std::endl;
	std::cout << std::left << std::setw(9) << "simple min(a, d): " << Fixed::min( a, d ) << std::endl;
	std::cout << std::left << std::setw(9) << "simple max(a, d): " << Fixed::max( a, d ) << std::endl;
	std::cout << std::left << std::setw(9) << "const min(a, c): " << Fixed::min( a, c ) << std::endl;
	std::cout << std::left << std::setw(9) << "const max(a, c): " << Fixed::max( a, c ) << std::endl;
	std::cout << std::left << std::setw(9) << "const min(c, b): " << Fixed::min( c, b ) << std::endl;
	std::cout << std::left << std::setw(9) << "const max(c, b): " << Fixed::max( c, b ) << std::endl;

	return 0;
}