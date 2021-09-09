#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include "RobotomyRequestForm.hpp" 
# include "PresidentialPardonForm.hpp" 
# include "ShrubberyCreationForm.hpp"

class Intern ;
	typedef Form*	(Intern::*Models)(std::string target) const;
class Intern
{
	class unknowFormRequest : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "an intern doesn't know how to make this kind of form.";
		}
	};
	
	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern &		operator=( Intern const & rhs );

		Form*		makeForm(std::string formName, std::string target) const throw(Intern::unknowFormRequest);
	
		static const uint			nbRequestKnow;
		static const Models			_forms[3];
		static const std::string	knowRequestName[3];
	private:
};

std::ostream &			operator<<( std::ostream & o, Intern const & i );

#endif /* ********************************************************** INTERN_H */