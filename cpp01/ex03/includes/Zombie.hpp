#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Zombie
{

	public:

		Zombie();
		// Zombie( Zombie const & src );
		~Zombie();
		Zombie(std::string name);
		Zombie(std::string type, std::string name);

		void		announce(void) const;
		std::string getName(void) const;
		std::string getType(void) const;
		void		setName(std::string name);


	private:
		std::string _name;
		std::string const _type;
};

#endif /* ********************************************************** ZOMBIE_H */