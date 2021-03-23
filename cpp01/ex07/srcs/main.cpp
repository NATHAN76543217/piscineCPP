# include <iostream>
# include <fstream>
# include <string>
# include "Sed.hpp"
# include <string.h>

int	main(int ac, char **av)
{
	if (ac != 4)
		std::cout << "usage: " << av[0] << " filename str1 str2 " << std::endl;
	else if (strlen(av[2]) == 0 || strlen(av[3]) == 0)
		std::cerr << "str1 and str2 must NOT be empty." << std::endl;
	else
	{
		std::cout << "open file: " << av[1] << std::endl;
		Sed sed(av[1]);
		sed.replace(av[2], av[3]);
	}
	return 0;
}
