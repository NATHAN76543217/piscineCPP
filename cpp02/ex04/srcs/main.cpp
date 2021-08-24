# include <iostream>
# include "Fixed.hpp"

bool	isOp(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	else
		return false;
}

Fixed	expression(std::string str)
{
	Fixed res;
	Fixed tmp = 0;
	size_t i = 0;
	size_t idx = 0;

	while (i < str.length() && str.at(i) != ')')
	{
		if (str.at(i) == '(')
		{
			std::cout << "(" << std::endl;
			res += expression(str.substr(i+1));
			str = str.substr(str.find(')'));
		}
		else if (isOp(str.at(i)))
		{
			switch (str.at(i))
			{
				case '+':
					res += tmp;
					break ;
				case '-':
					res -= tmp;
					break ;
				case '*':
					res *= tmp;
					break ;
				case '/':
					res /= tmp;
					break ;
			}
		}
		else if (str.at(i) >= '0' && str.at(i) <= '9')
		{
			// std::cout << tmp << " " << i << std::endl;
			tmp = std::stof(&(str[i]), &idx);
			i += idx;
			std::cout << tmp << " " << i << " c : '" << str.at(i) << "'" << std::endl;
			// str = str.substr(i);
		}
		if (str.at(i) == ')')
			break;
		i++;
	}
	std::cout << "return -> " << res << std::endl;
	return res;
}

int	main(int ac, char **av )
{
	int i = 1;

	if (ac < 2) {
		std::cout << "Error arguments:" << std::endl << av[0] << " expression1 [expression2, ...] "<< std::endl;
		return -1;
	}

	while (i < ac - 1) {
		std::cout << "Expression: " << av[i] << std::endl;
		std::cout << "Result: " << expression(av[i]) << std::endl;
		++i;
	}
	return 0;
}