#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class PresidentialPardonForm : public Form
{

	public:

		PresidentialPardonForm();
		PresidentialPardonForm(std::string name);
		PresidentialPardonForm( PresidentialPardonForm const & src );
		~PresidentialPardonForm();

		PresidentialPardonForm &		operator=( PresidentialPardonForm const & rhs );

		void				execute(Bureaucrat const & B) const throw(Form::gradeTooLowException, Form::formNotSigned);
		Form*				create(std::string target) const;

	private:

};

#endif /* ****************************************** PRESIDENTIALPARDONFORM_H */