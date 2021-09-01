#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

	public:
		WrongCat();
		WrongCat( WrongCat const & src );
		~WrongCat();

		WrongCat &		operator=( WrongCat const & rhs );

	private:

};

std::ostream &			operator<<( std::ostream & o, WrongCat const & i );

#endif /* ************************************************************* CAT_H */