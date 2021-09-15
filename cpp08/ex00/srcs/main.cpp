#include <vector>
#include <list>
#include <string>
#include <iostream>
#include "easyfind.tpp"

int	main()
{
	std::vector<int> v;

	std::cout << "-- with vector --" << std::endl;
	{
		for (int i = 0; i < 5; i++)
			v.push_back(i);
		int ret = easyfind<std::vector<int> >(v, 0);
		std::cout << "0 - founded: " << ret << std::endl;
		ret = easyfind<std::vector<int> >(v, 4);
		std::cout << "4 - founded: " << ret << std::endl;
		ret = easyfind<std::vector<int> >(v, 7);
		std::cout << "7 - founded: " << ret << std::endl;
	}
	std::cout << std::endl << "-- with list --" << std::endl;
	{
		std::list<int> l;
		for (int i = 0; i < 5; i++)
			l.push_back(i);
			int ret = easyfind<std::list<int> >(l, 0);
		std::cout << "0 - founded: " << ret << std::endl;
		ret = easyfind<std::list<int> >(l, 4);
		std::cout << "4 - founded: " << ret << std::endl;
		ret = easyfind<std::list<int> >(l, 7);
		std::cout << "7 - founded: " << ret << std::endl;
	}
	std::cout << std::endl << "-- with empty list --" << std::endl;
	{
		std::list<int> l;
		int ret = easyfind<std::list<int> >(l, 3);
		std::cout << "3 - founded: " << ret << std::endl;
	}
	std::cout << std::endl << "-- with float list --" << std::endl;
	{
		std::list<float> l;
		for (float i = 0.0f; i < 5.0f; i++)
			l.push_back(i);
		int ret = easyfind<std::list<float> >(l, 3);
		std::cout << "3 - founded: " << ret << std::endl;
		ret = easyfind<std::list<float> >(l, 5);
		std::cout << "5 - founded: " << ret << std::endl;
	}
	// std::cout << std::endl << "-- with string list --" << std::endl;
	// {
	// 	std::string str[5] = {"un", "deux", "trois", "quatre", "cinq"};
	// 	std::list<std::string> l;
	// 	for (int i = 0; i < 5; i++)
	// 		l.push_back(str[i]);
	// 	int ret = easyfind<std::list<std::string> >(l, 3);
	// 	std::cout << "3 - founded: " << ret << std::endl;
	// }
	return 0;
}