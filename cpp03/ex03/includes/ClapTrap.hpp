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
		ClapTrap( std::string name, unsigned int hp, unsigned int ep, unsigned int attack );
		ClapTrap( ClapTrap const & src );
		~ClapTrap();

		ClapTrap &		operator=( ClapTrap const & rhs );

		void		attack(ClapTrap & target) const;
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		unsigned int		getHp( void ) const;
		unsigned int		getEp( void ) const;
		unsigned int		getAttack( void ) const;
		std::string	const	&getName( void ) const;

		void				setName( std::string name );
	
	protected:
		std::string		_name;
		unsigned int	_hp;
		unsigned int	_ep;
		unsigned int	_attack;
		
	private:


};

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i );

#endif /* ******************************************************** CLAPTRAP_H */