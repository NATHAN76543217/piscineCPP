# include "Karen.hpp"

int main(int ac, char **av)
{
	int i = 0;
	Karen karen;

	if (ac != 2)
	{
		std::cout << av[0] << " level" << std::endl;
		return 1;
	}
	for (i = 0; i < Karen::nbr_levels; i++)
	{
		if (Karen::levelNames[i] == av[1])
			break ;
	}
	switch(i)
	{
		case (0): 
			std::cout << "[ DEBUG ]" << std::endl;
			karen.complain("DEBUG");
			std::cout << std::endl;
		case (1):
			std::cout << "[ INFO ]" << std::endl;
			karen.complain("INFO");
			std::cout << std::endl;
		case (2):
			std::cout << "[ WARNING ]" << std::endl;
			karen.complain("WARNING");
			std::cout << std::endl;
		case (3): 
			std::cout << "[ ERROR ]" << std::endl;
			karen.complain("ERROR");
			std::cout << std::endl;
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
	}
	return 0;
}