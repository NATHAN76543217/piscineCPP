# include <iostream>
# include <string>
#include <iomanip>

void	toChar(std::string raw)
{
	try {
		char cval;
		if (raw.length() == 1 && raw.at(0) && !isnumber(raw.at(0)))
			cval = static_cast<char>(raw.at(0));
		else
			cval = static_cast<char>(std::stoi(raw));
		if (isprint(cval))
			std::cout << "char: '" << cval << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << "char: impossible" << std::endl;
	}
}

void		toInt(std::string val)
{
	try
	{
		int res = std::stoi(val);
		std::cout << "int: " << static_cast<int>(res) << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cout << "int: impossible" << std::endl;
	}
}

void		toFloat(std::string val)
{
	try
	{
		float valf = std::stof(val);
		std::cout << std::fixed << std::setprecision(1) << "float: " << valf << "f" << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cout << "float: impossible" << std::endl;
	}
	
}

void		toDouble(std::string val)
{
	try {
		double vald = static_cast<double>(std::stod(val));
		std::cout << std::fixed << std::setprecision(1) << "double: " << vald << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << "double: impossible" << std::endl;
	}
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Bad argument:" << std::endl << av[0] << " cppLitteralValue" << std::endl;
		return EXIT_FAILURE;
	}
	std::string value(av[1]);

	toChar(value);
	toInt(value);
	toFloat(value);
	toDouble(value);
	return EXIT_SUCCESS;
}