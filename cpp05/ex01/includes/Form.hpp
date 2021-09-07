#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureautique.hpp"

class Form
{

	public:

		Form();
		Form( Form const & src );
		~Form();

		Form &		operator=( Form const & rhs );

		void		beSigned(Bureaucrat & B);
		bool		isSigned( void ) const;

		std::string	getName( void ) const;
		uint		getSigningGrade( void ) const;
		uint		getExecutingGrade( void ) const;
	private:
		std::string	_name;
		bool		_signed;
		uint		_signing_grade;
		uint		_executing_grade;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */