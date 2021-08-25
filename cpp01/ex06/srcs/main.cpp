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
			karen.complain("DEBUG");
		case (1):
			karen.complain("INFO");
		case (2):
			karen.complain("WARNING");
		case (3): 
			karen.complain("ERROR");
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
	}
	return 0;
}