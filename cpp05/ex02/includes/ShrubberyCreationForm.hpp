#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
	public:
		class fileNotOpened : public std::exception
		{
			virtual const char *what() const throw()
			{
				return "target file cannot be openned";
			}
		};

	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		~ShrubberyCreationForm();

		void		execute(Bureaucrat const & B) const throw (Form::gradeTooLowException, Form::formNotSigned);

		static const std::string	tree[];
		static const uint			treeByRow;
		static const uint			rowByTree;
	private:

};

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */