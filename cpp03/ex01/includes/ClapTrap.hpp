#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <iomanip>
# include <string>

class ClapTrap
{

	public:

		ClapTrap();
		ClapTrap( std::string name );
		ClapTrap( std::string name, int hp, int ep, int attack );
		ClapTrap( ClapTrap const & src );
		~ClapTrap();

		ClapTrap &		operator=( ClapTrap const & rhs );

		void		attack(std::string & target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		std::string	getName( void ) const;
		int			getHp( void ) const;
		int			getEp( void ) const;
		int			getAttack( void ) const;

		void	setName( std::string name );

	private:
		std::string _name;
		int			_hp;
		int			_ep;
		int			_attack;


};

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i );

#endif /* ******************************************************** CLAPTRAP_H */