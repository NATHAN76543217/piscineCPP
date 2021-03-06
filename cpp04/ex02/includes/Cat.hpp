#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{

	public:

		Cat();
		Cat( Cat const & src );
		~Cat();

		Cat &		operator=( Cat const & rhs );

		void		makeSound( void ) const;
		
		std::string	getIdea( unsigned int const i ) const;
		void		setIdea( unsigned int const i, std::string idea);

	private:
		Brain*		_brain;
};

std::ostream &			operator<<( std::ostream & o, Cat const & i );

#endif /* ************************************************************* CAT_H */