#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <string>
# include <fstream>

class Replace
{

	public:

		Replace(std::string filename);
		~Replace();

		void replace(std::string s1, std::string s2);
	private:
		std::string		_filename;
		std::string		_outname;
		std::ifstream	_ifs;
		std::ofstream	_ofs;

};

#endif /* ********************************************************* REPLACE_H */