#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Ice : public AMateria
{

	public:
		Ice();
		Ice(std::string const & type);
		Ice( Ice const & src );
		~Ice();

		Ice &		operator=( Ice const & rhs );

		AMateria*	clone( void ) const;
		void		use(ICharacter & target);
	
};

std::ostream &			operator<<( std::ostream & o, Ice const & i );

#endif /* ************************************************************* ICE_H */