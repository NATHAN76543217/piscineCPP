#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat
{

	class GradeTooHighException : public std::exception
	{
		virtual const char * what () const throw ()
    	{
	    	return "This grade is too high for a Bureaucrate";
    	}
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char * what () const throw ()
	    {
	    	return "This grade is too low for a Bureaucrate";
	    }
	};

	public:

		Bureaucrat();
		Bureaucrat( std::string name, uint grade ) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		// Bureaucrat &		operator=( Bureaucrat const & rhs );


		void				promote( void );
		void				retrograde( void );
		void				signForm( Form & f) const;
		void				executeForm( Form & f) const;

		std::string	const &	getName( void ) const;
		uint				getGrade( void ) const;
		void				setGrade( uint const grade ) throw(Bureaucrat::GradeTooHighException, Bureaucrat::GradeTooLowException);
		
		static const uint			gradeMax;
		static const uint			gradeMin;
		static const std::string	defaultName;
	
	private:
		std::string const	_name;
		uint				_grade;
	

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */