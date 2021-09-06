#include "Fixed.hpp"
#include <iomanip>
int main()
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	Fixed const z(-10.1f);
	
	a = Fixed(1234.4321f);
	
	std::cout << "a is " << std::left << std::setw(7) << a << std::endl;
	std::cout << "b is " << std::left << std::setw(7) << b << std::endl;
	std::cout << "c is " << std::left << std::setw(7) << c << std::endl;
	std::cout << "d is " << std::left << std::setw(7) << d << std::endl;
	std::cout << "z is " << std::left << std::setw(7) << z << std::endl << std::endl;

	std::cout << "a is " << std::left << std::setw(5) << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << std::left << std::setw(5) << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << std::left << std::setw(5) << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << std::left << std::setw(5) << d.toInt() << " as integer" << std::endl;
	std::cout << "z is " << std::left << std::setw(5) << z.toInt() << " as integer" << std::endl << std::endl;
	return 0;
}
