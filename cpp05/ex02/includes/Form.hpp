#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	class alreadySignedException : public std::exception
	{
		virtual const char *what() const throw()
		{
			return "This Form is already signed";
		}
	};

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

		void				beSigned(Bureaucrat const & B);
		virtual void		execute(Bureaucrat const & B) const = 0;

		bool		isSigned( void ) const;
		std::string	getName( void ) const;
		std::string	getTarget( void ) const;
		uint		getSigningGrade( void ) const;
		uint		getExecutingGrade( void ) const;

		void		setSigningGrade( uint signingGrade)
						throw(Form::gradeTooHighexception, Form::gradeTooLowexception);
		void		setExecutingGrade( uint executingGrade)
						throw(Form::gradeTooHighexception, Form::gradeTooLowexception);
		void		setTarget( std::string target );

		static const uint			gradeMax;
		static const uint			gradeMin;
		static const std::string	defaultName;

	private:
		std::string	_name;
		bool		_signed;
		uint		_signing_grade;
		uint		_executing_grade;
		std::string	_target;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */