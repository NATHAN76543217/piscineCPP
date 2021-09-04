#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	this->_brain->setIdea(0, "Eat some cat food");
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat( const Cat & src ) : Animal(src)
{
	this->_brain = new Brain(*(src._brain));
	std::cout << "Cat copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << std::endl << "My tough was:" << std::endl << this->_brain->getIdea(0);
	std::cout << std::endl << this->_brain->getIdea(1) << std::endl;
	if (this->_brain != NULL)
		delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	if ( this != &rhs )
	{
		Animal::operator=(rhs);
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Cat const & i )
{
	o << "CatType = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void		Cat::makeSound( void ) const
{
	std::cout << "Miaaaouuuuw" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string		Cat::getIdea( unsigned int const i ) const
{
	return this->_brain->getIdea(i);
}

void			Cat::setIdea( unsigned int const i, std::string idea)
{
	this->_brain->setIdea(i, idea);
}

/* ************************************************************************** */