#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() : Animal(), _brain(NULL)
{
	this->_type = "Dog";
	this->_brain = new Brain();
	this->_brain->setIdea(0, "Eat some dog food");
	std::cout << "Dog constructor called" << std::endl;

}

Dog::Dog( const Dog & src ) : Animal(src), _brain(NULL)
{
	this->_brain = new Brain(*(src._brain));
	std::cout << "Dog copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	std::cout << std::endl << "My tough was:" << std::endl << this->_brain->getIdea(0);
	std::cout << std::endl << this->_brain->getIdea(1) << std::endl;
	if (this->_brain != NULL)
		delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	if ( this != &rhs )
	{
		Animal::operator=(rhs);
		if (rhs._brain == NULL)
			this->_brain->operator=(*(rhs._brain));
		else
			this->_brain = new Brain();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Dog const & i )
{
	o << "DogType = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void				Dog::makeSound( void ) const
{
	std::cout << "Ouuaf Ouaf wouf" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string		Dog::getIdea( unsigned int const i ) const
{
	return this->_brain->getIdea(i);
}

void			Dog::setIdea( unsigned int const i, std::string idea)
{
	this->_brain->setIdea(i, idea);
}

/* ************************************************************************** */