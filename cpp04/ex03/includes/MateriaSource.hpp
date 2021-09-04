#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{

	public:

		MateriaSource();
		MateriaSource( MateriaSource const & src );
		~MateriaSource();

		MateriaSource &		operator=( MateriaSource const & rhs );

		void				learnMateria( AMateria* materia );
		AMateria*			createMateria( std::string const & type );

		std::string const	getMateriaType( uint idx ) const;
		uint				getNbLearned( void ) const;

		static uint const maxMaterias;

	private:

		uint			_learned;
		AMateria*		_materia[4];

		void		_init_materias( void );

};

std::ostream &			operator<<( std::ostream & o, MateriaSource const & i );

#endif /* *************************************************** MATERIASOURCE_H */