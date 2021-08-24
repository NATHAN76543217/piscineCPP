# include <iostream>
# include <iomanip>
# include "Fixed.hpp"

int	main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ));
	Fixed const c( 2 );

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
	std::cout << std::left << std::setw(9) << "epsilon: " << a.getEpsilon() << std::endl;
	std::cout << std::left << std::setw(9) << "++a: " << ++a << std::endl;
	std::cout << std::left << std::setw(9) << "a++: " << a++ << std::endl;
	std::cout << std::left << std::setw(9) << "a: " << a << std::endl;
	std::cout << std::left << std::setw(9) << "--a: " << --a << std::endl;
	std::cout << std::left << std::setw(9) << "a--: " << a-- << std::endl;
	std::cout << std::left << std::setw(9) << "a: " << a << std::endl;
	std::cout << std::left << std::setw(9) << "b: " << b << std::endl;
	std::cout << std::left << std::setw(9) << "c: " << c << std::endl;
	std::cout << std::left << std::setw(9) << "min(a, c): " << Fixed::min( a, c ) << std::endl;
	std::cout << std::left << std::setw(9) << "max(a, c): " << Fixed::max( a, c ) << std::endl;
	std::cout << std::left << std::setw(9) << "min(c, b): " << Fixed::min( c, b ) << std::endl;
	std::cout << std::left << std::setw(9) << "max(c, b): " << Fixed::max( c, b ) << std::endl;

	return 0;
}