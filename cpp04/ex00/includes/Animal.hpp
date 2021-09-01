#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{

	public:

		Animal();
		Animal( Animal const & src );
		~Animal();

		Animal &		operator=( Animal const & rhs );

		virtual void	makeSound( void ) const;

		std::string		getType( void ) const;

	protected:
		std::string	_type;

};

#endif /* ********************************************************** ANIMAL_H */