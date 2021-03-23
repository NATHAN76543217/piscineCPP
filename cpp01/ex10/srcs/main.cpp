# include "Cat.hpp"

int	main(int ac, char **av)
{
	Cat cat;

	if (ac == 1)
		cat.readStdin();
	for (int i = 1; i < ac; i++)
	{
		cat.file(av[i]);
	}
    return 0;
}
