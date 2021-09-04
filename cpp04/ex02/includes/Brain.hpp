#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{

	public:

		Brain();
		Brain( Brain const & src );
		~Brain();

		static	const unsigned int nbIdeas; 
		Brain &		operator=( Brain const & rhs );

		std::string	getIdea( unsigned int const i ) const;
		void		setIdea( unsigned int const i, std::string idea);
	private:
		std::string _ideas[100];
};

std::ostream &			operator<<( std::ostream & o, Brain const & i );

#endif /* *********************************************************** BRAIN_H */