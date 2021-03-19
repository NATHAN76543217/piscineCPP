#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include <iostream>
# include <string>
# include <random>
# include "Zombie.hpp"
class ZombieEvent
{

	public:

		ZombieEvent();
		ZombieEvent( ZombieEvent const & src );
		~ZombieEvent();

		void		randomChump();
		void		setZombieType (std::string type);
		Zombie		*newZombie (std::string name);

	private:
		std::string _type;
		static const std::string nameList[];

		std::string	getRandomName() const;
};

#endif /* ***************************************************** ZOMBIEEVENT_H */