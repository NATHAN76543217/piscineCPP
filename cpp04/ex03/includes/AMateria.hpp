#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

# include "ICharacter.hpp"

class ICharacter;

class AMateria
{

	public:

		AMateria( std::string const & type );
		AMateria( AMateria const & src );
		virtual ~AMateria();

		AMateria &		operator=( AMateria const & rhs );
		
		virtual AMateria	*clone( void ) const = 0;
		virtual void		use(ICharacter& target);
		std::string const &	getType( void ) const; //Returns the materia type

	protected:

		std::string const	_type;

	private:

};

std::ostream &			operator<<( std::ostream & o, AMateria const & i );

#endif /* ******************************************************** AMATERIA_H */