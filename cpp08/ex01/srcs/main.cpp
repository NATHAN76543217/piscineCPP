#include <vector>
#include <list>
#include <string>
#include <iostream>
#include "Span.hpp"

int	main()
{
	Span sp = Span(5);
	
	std::cout << "__Create span(5)__" << std::endl;
	try {
		std::cout << "size:    " << sp.getSize() << std::endl;
		std::cout << "shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "longest: " << sp.longestSpan() << std::endl << std::endl;
	} catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);

	std::cout << std::endl << "__add 4 elements__" << std::endl;
	std::cout << "size:    " << sp.getSize() << std::endl;
	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest: " << sp.longestSpan() << std::endl << std::endl;
	
	std::cout << "__add a number__" << std::endl;
	sp.addNumber(20);
	std::cout << "size:    " << sp.getSize() << std::endl;
	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest: " << sp.longestSpan() << std::endl << std::endl;
	std::cout << "__add another number__" << std::endl;
	try
	{
		sp.addNumber(25);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}	
	std::cout << std::endl << "__with iterable__" << std::endl;
	std::cout << "vector = ";
	std::vector<int> vTest;
	for (int i = 0; i < 100; i++)
		vTest.push_back(i);
	for (std::vector<int>::const_iterator it = vTest.begin(); it != vTest.end(); it++)
	{
		std::cout << *it << ", ";
	}
	Span sp2(vTest.begin(), vTest.end());
	std::cout << std::endl;
	std::cout << "size:    " << sp2.getSize() << std::endl;
	std::cout << "shortest: " << sp2.shortestSpan() << std::endl;
	std::cout << "longest: " << sp2.longestSpan() << std::endl;

	for (int i = 105; i < 20000; i++)
		vTest.push_back(i + i);
	for (std::vector<int>::const_iterator it = vTest.begin(); it != vTest.end(); it++)
	{
		std::cout << *it << ", ";
	}
	Span sp3(vTest.begin(), vTest.end());
	std::cout << std::endl;
	std::cout << "size:    " << sp3.getSize() << std::endl;
	std::cout << "shortest: " << sp3.shortestSpan() << std::endl;
	std::cout << "longest: " << sp3.longestSpan() << std::endl;
	return 0;
}