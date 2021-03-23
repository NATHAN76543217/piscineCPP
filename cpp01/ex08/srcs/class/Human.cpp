#include "Human.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Human::Human()
{
}

Human::Human(std::string name) : _name(name) 
{
	std::string	skills[] = {"melee", "ranged", "shout"};
	Actions		actions[3] = { &Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout };
	
	this->actions = new Actions[3];
	for (int i = 0; i < 3 ; i++)
	{
		this->_skills[i] = skills[i];
		this->actions[i] = actions[i];
	}
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Human::~Human()
{
	delete[] this->actions;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Human::action(std::string const & action_name, std::string const & target)
{
	for (int i = 0; i < 3; i++)
	{
		if (this->_skills[i] == action_name)
    	{
    	    (this->*(actions[i]))(target);
    	    break;
    	}
	}
	return ;
}

void	Human::meleeAttack(std::string const & target)
{
	std::cout << this->_name << " use a melee attack on " << target << "." << std::endl;
	return ;
}

void	Human::rangedAttack(std::string const & target)
{
	std::cout << this->_name << " use a ranged attack on " << target << std::endl;
	return ;
}

void	Human::intimidatingShout(std::string const & target)
{
	std::cout << this->_name << " use an intimidating shout on " << target << std::endl;
	return ;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */