#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include "easyfind.tpp"

template<typename T>
void	printCnt(T v)
{
	for (typename T::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
}

template<typename T>
void		test(void)
{
	T v;

	for (int i = 0; i < 5; i++)
		v.push_back(i);
	printCnt(v);
	bool ret = easyfind<T>(v, 0);
	std::cout << "Search: 0 - founded: " << ret << std::endl;
	ret = easyfind<T>(v, 4);
	std::cout << "Search: 4 - founded: " << ret << std::endl;
	ret = easyfind<T>(v, 7);
	std::cout << "Search: 7 - founded: " << ret << std::endl;
}

int	main()
{

	std::cout << std::boolalpha << std::endl << "-- with vector (int)--" << std::endl;
	test<std::vector<int> >();
	std::cout << std::boolalpha << std::endl << "-- with vector (float)--" << std::endl;
	test<std::vector<float> >();
	std::cout << std::boolalpha << std::endl << "-- with list (int) --" << std::endl;
	test<std::list<int> >();
	std::cout << std::boolalpha << std::endl << "-- with list (float) --" << std::endl;
	test<std::list<float> >();
	std::cout << std::boolalpha << std::endl << "-- with deque (int) --" << std::endl;
	test<std::deque<int> >();
	std::cout << std::boolalpha << std::endl << "-- with deque (float) --" << std::endl;
	test<std::deque<float> >();
	return 0;
}