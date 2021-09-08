#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <iomanip>
# include <string>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap( ClapTrap const & src );
		~ClapTrap();

		ClapTrap &		operator=( ClapTrap const & rhs );

		void		attack(std::string & target);
		void		takeDamage( uint amount);
		void		beRepaired( uint amount);

		std::string	getName( void ) const;
		int			getHp( void ) const;
		int			getEp( void ) const;
		int			getAttack( void ) const;

	private:
		std::string _name;
		int			_hp;
		int			_ep;
		int			_attack;

};

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i );

#endif /* ******************************************************** CLAPTRAP_H */