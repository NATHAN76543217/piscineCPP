#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include <iostream>
# include <string>
# include <random>
# include "utils.hpp"
# include "Zombie.hpp"

class ZombieHorde
{

	public:

		ZombieHorde(int N);
		~ZombieHorde();
		void announce(void);

	private:
		Zombie	*_zomlist;
		int		_nb_zombies;
		static const std::string _nameList[]; 
		
		std::string	_getRandomName() const;


};

#endif /* ***************************************************** ZOMBIEHORDE_H */