#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class Animal
{

	public:

		Animal();
		Animal( Animal const & src );
		virtual ~Animal();

		Animal &		operator=( Animal const & rhs );

		virtual void	makeSound( void ) const = 0;

		std::string		getType( void ) const;

	protected:
		std::string	_type;

};

#endif /* ********************************************************** ANIMAL_H */