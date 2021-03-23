#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include <fstream>

class Cat
{

	public:

		Cat();
		~Cat();

		void			readStdin(void);
		void			file(std::string filename);
		std::ifstream	&getIfs(void);
		std::ofstream	&getOfs(void);
	private:
		std::ifstream *_ifs;
		std::ofstream *_ofs;

	void	read(void);
	int		openInFile(std::string filename);

};

#endif /* ************************************************************* CAT_H */