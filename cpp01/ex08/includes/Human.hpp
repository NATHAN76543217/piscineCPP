#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <iostream>
# include <string>

class Human
{
	public:

		Human();
		Human(std::string name);

		~Human();

		typedef		void (Human::*Actions)(std::string const & target);

		Actions		*actions;
		void		action(std::string const & action_name, std::string const & target);

	private:
		std::string _name;
	    std::string _skills[3];

		void	meleeAttack(std::string const & target);
		void	rangedAttack(std::string const & target);
		void	intimidatingShout(std::string const & target);
};

#endif /* *********************************************************** HUMAN_H */