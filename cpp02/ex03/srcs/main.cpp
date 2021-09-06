# include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

/*
**             M
**  A\   
** ||    Q    
** ||  O    \
**  C || N ||  B
**
** D=(1.7142857)
*/

# define INTER 1.7142857f

int	main( void )
{
	Fixed zero;
	Fixed un(1.0f);
	Fixed deux(2);
	Fixed trois(3);
	Fixed quatre(4);
	Fixed real(INTER);
	Fixed limite(INTER - Fixed::getEpsilon());

	Point A(zero, trois);
	Point B(quatre, zero);
	Point C(zero, zero);

	Point M(quatre, quatre);
	Point N(deux, Fixed(0));
	Point O(un, un);
	Point P(limite, limite);
	Point Q(real, real);

	std::cout << "A = " << A << std::endl;
	std::cout << "B = " << B << std::endl;
	std::cout << "C = " << C << std::endl;
	std::cout << "M = " << M << std::endl;
	std::cout << "N = " << N << std::endl;
	std::cout << "O = " << O << std::endl;
	std::cout << "P = " << P << std::endl;
	std::cout << "Q = " << Q << std::endl << std::endl;
	std::cout << "bsp (ABC) -> M: " << bsp(A, B, C, M) << std::endl;
	std::cout << "bsp (ABC) -> N: " << bsp(A, B, C, N) << std::endl;
	std::cout << "bsp (ABC) -> O: " << bsp(A, B, C, O) << std::endl;
	std::cout << "bsp (ABC) -> P: " << bsp(A, B, C, P) << std::endl;
	std::cout << "bsp (ABC) -> Q: " << bsp(A, B, C, Q) << std::endl;
	return 0;
}