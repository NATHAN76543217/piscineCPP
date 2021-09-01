#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{

	public:

		FragTrap();
		FragTrap( std::string name );
		FragTrap( FragTrap const & src );
		~FragTrap();

		void	highFivesGuys(void) const;

	protected:
		static const unsigned int _init_hp;
		static const unsigned int _init_ep;
		static const unsigned int _init_attack;

};

std::ostream &			operator<<( std::ostream & o, FragTrap const & i );

#endif /* ******************************************************** FRAGTRAP_H */