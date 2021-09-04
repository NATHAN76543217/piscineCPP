#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{

	public:

		Character();
		Character( std::string const & name );
		Character( Character const & src );
		~Character();

		Character &		operator=( Character const & rhs );
		
		void					equip( AMateria* m);
		void					unequip( int idx);
		void					use( int idx, ICharacter& target);

		std::string const & 	getName() const;
		AMateria const*			getItem(uint idx) const;

		static uint const		maxMaterias = 4;

	private:

		std::string		_name;
		uint			_equiped;
		AMateria		*_materia[maxMaterias];

		void			_init_materias( void );


};

std::ostream &			operator<<( std::ostream & o, Character const & i );

#endif /* ******************************************************* CHARACTER_H */