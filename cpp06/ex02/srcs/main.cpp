#include <string>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate( void )
{
	Base*	base_ptr = nullptr;

	switch (std::rand() % 3)
	{
		case 0:
			base_ptr = new A();
			break ;
		case 1:
			base_ptr = new B();
			break ;
		case 2:
			base_ptr = new C();
			break ;
		default:
			std::cout << "unhandled index" << std::endl;
			break;
	}
	return base_ptr;
}

void	identify( Base *p)
{
	A* a = dynamic_cast<A*>(p);
	B* b = dynamic_cast<B*>(p);
	C* c = dynamic_cast<C*>(p);
	std::cout << "type is: " ;
	if (a)
		std::cout << "A" << std::endl;
	else if (b)
		std::cout << "B" << std::endl;
	else if (c)
		std::cout << "C" << std::endl;
	else
		std::cerr << "unknow type" << std::endl;
	return ;
}

void	identify( Base &p)
{
	std::cout << "type is: " ;
	try 
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return ;
	} 
	catch(std::bad_cast const &e)
	{
	}
	try 
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return ;
	} 
	catch(std::bad_cast const &e)
	{
	}
	try 
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return ;
	} 
	catch(std::bad_cast const &e)
	{
		std::cerr << "unknow  type" << std::endl;
	}
	return ;
}


int		main()
{
	std::srand(std::time(NULL));

	Base *b1 = generate();
	Base *b2 = generate();
	Base *b3 = generate();
	std::cout << std::endl << "--pointers--" << std::endl;
	identify(b1);
	identify(b2);
	identify(b3);

	std::cout << std::endl << "--references--" << std::endl;
	identify(*b1);
	identify(*b2);
	identify(*b3);

	std::cout << std::endl;
	delete b1;
	delete b2;
	delete b3;
	return EXIT_SUCCESS;
}