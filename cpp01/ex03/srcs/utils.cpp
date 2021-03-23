#include "utils.hpp"

std::string	truncate(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str; 
}

bool	youWantTo(std::string str)
{
	std::string type;

	do
	{
		std::cout << "Do you want to " << str << "? [y/n]" << std::endl;
		std::getline(std::cin, type);
	}
	while(type!="y" && type!="n");	
	if (type=="y")
		return true;
	return false;
}

int	getRandomIndex(int from, int to)
{
	std::random_device seedGen; // obtain a random number (seed) from hardware
    std::mt19937 gen(seedGen()); // create generator from seed
    std::uniform_int_distribution<> distr(from, to); // define the range

	return distr(gen);
}
