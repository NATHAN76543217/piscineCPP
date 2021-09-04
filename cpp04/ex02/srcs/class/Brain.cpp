#include "Brain.hpp"

/*
** ------------------------------- STATIC --------------------------------
*/

const unsigned int	Brain::nbIdeas = 100;
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain( const Brain & src )
{
	this->operator=(src);
	std::cout << "Brain copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
	std::cout << "Brain destructor" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &				Brain::operator=( Brain const & rhs )
{
	if ( this != &rhs )
	{
		for (unsigned int i = 0; i < Brain::nbIdeas; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Brain const & B )
{
	o << "Brain = " << std::endl;
	for (unsigned int i = 0; i < Brain::nbIdeas; i++)
		o << "[" << i << "] " << B.getIdea(i) << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string		Brain::getIdea( unsigned int const i ) const
{
	if (i >= Brain::nbIdeas)
		return "Brain: I dont have so many ideas";
	return this->_ideas[i];
}

void			Brain::setIdea( unsigned int const i, std::string idea )
{
	if (i >= Brain::nbIdeas)
	{
		std::cout << "Brain: This is too meaningless to be remebered" << std::endl;
		return ;
	}
	this->_ideas[i] = idea;
}

/* ************************************************************************** */