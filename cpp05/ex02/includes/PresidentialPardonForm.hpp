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

		void				execute(Bureaucrat const & B) const throw(Form::gradeTooLowException, Form::formNotSigned);

	private:

};

#endif /* ****************************************** PRESIDENTIALPARDONFORM_H */