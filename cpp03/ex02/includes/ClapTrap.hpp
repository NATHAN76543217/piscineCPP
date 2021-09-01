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

		void		attack(std::string const& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		std::string	const	&getName( void ) const;
		unsigned int		getHp( void ) const;
		unsigned int		getEp( void ) const;
		unsigned int		getAttack( void ) const;

		void	setName( std::string name );

	private:
		std::string		_name;
		unsigned int	_hp;
		unsigned int	_ep;
		unsigned int	_attack;


};

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i );

#endif /* ******************************************************** CLAPTRAP_H */