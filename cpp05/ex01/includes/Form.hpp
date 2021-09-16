#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public :
		class gradeTooHighexception : public std::exception
		{
			virtual const char *what() const throw()
			{
				return "This grade is too high for this Form";
			}
		};

		class gradeTooLowexception : public std::exception
		{
			virtual const char *what() const throw()
			{
				return "This grade is too low for this Form";
			}
		};

	public:

		Form();
		Form(std::string name, uint signingGrade, uint executingGrade);
		Form( Form const & src );
		~Form();

		Form &		operator=( Form const & rhs );

		void		beSigned(Bureaucrat const & B);

		bool		isSigned( void ) const;
		std::string	getName( void ) const;
		uint		getSigningGrade( void ) const;
		uint		getExecutingGrade( void ) const;

		void		setSigningGrade( uint signingGrade);
		void		setExecutingGrade( uint executingGrade);

		static const uint			gradeMax;
		static const uint			gradeMin;
		static const std::string	defaultName;
	private:
		std::string	_name;
		bool		_signed;
		uint		_signing_grade;
		uint		_executing_grade;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */