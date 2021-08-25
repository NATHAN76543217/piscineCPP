#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
	public:

		Weapon(std::string type);
		~Weapon();

		void		setType(std::string type);
		std::string	getType( void ) const;

	private:
		std::string _type;
};

#endif /* ********************************************************** WEAPON_H */