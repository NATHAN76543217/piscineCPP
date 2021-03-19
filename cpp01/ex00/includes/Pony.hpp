#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>
# include <string>

class Pony
{

	public:

		Pony();
		Pony(const std::string name);

		~Pony();

		void		jump(void);
		void		run(void);
		void		look(void);


	private:
		int			age;
		std::string	name;
		std::string	color;
		std::string	gender;
		std::string	favorite_grass;

};


#endif /* ************************************************************ PONY_H */