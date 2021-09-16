#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	protected:
		class formNotSigned : public std::exception
		{
			virtual const char *what() const throw()
			{
				return "This form is not signed";
			}
		};

		class alreadySignedException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return "This Form is already signed";
			}
		};

		class gradeTooHighException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return "This grade is too high for this Form";
			}
		};

		class gradeTooLowException : public std::exception
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

		Form &				operator=( Form const & rhs );

		void				beSigned(Bureaucrat const & B) throw (Form::gradeTooLowException, Form::alreadySignedException);
		void				checkAllowance(Bureaucrat const & B) const throw (Form::gradeTooLowException, Form::formNotSigned);
		virtual void		execute(Bureaucrat const & B) const throw (Form::gradeTooLowException, Form::formNotSigned) = 0;

		bool				isSigned( void ) const;
		std::string			getName( void ) const;
		std::string			getTarget( void ) const;
		uint				getSigningGrade( void ) const;
		uint				getExecutingGrade( void ) const;

		void				setSigningGrade( uint signingGrade)
								throw(Form::gradeTooHighException, Form::gradeTooLowException);
		void				setExecutingGrade( uint executingGrade)
								throw(Form::gradeTooHighException, Form::gradeTooLowException);
		void				setTarget( std::string target );

		static const uint			gradeMax;
		static const uint			gradeMin;
		static const std::string	defaultName;

	protected:
		std::string		_name;
		bool			_signed;
		uint			_signing_grade;
		uint			_executing_grade;
		std::string		_target;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */