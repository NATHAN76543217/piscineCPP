#include <iostream>

int main(int ac, char **av)
{
	int i;
	int a;

	i = 1;
	a = 0;
	if (ac <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (i < ac)
		{
			while (av[i][a] != '\0')
				std::cout << (char) toupper(av[i][a++]);
			a = 0;
			i++;
		}
		std::cout << std::endl;
	}
	return 0;
}