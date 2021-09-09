#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <unistd.h>

# include "Form.hpp"

class RobotomyRequestForm : public Form
{

	public:

		RobotomyRequestForm();
		RobotomyRequestForm(std::string name);
		RobotomyRequestForm( RobotomyRequestForm const & src );
		~RobotomyRequestForm();

		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );

		void		execute(Bureaucrat const & B) const throw (Form::gradeTooLowException, Form::formNotSigned);
		Form*		create(std::string target) const;

	private:

};

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H */