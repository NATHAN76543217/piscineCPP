#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
	public:
		class GradeTooHighException : public std::exception
		{
			const char * what () const throw ()
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

		void				promote( void );
		void				retrograde( void );
	
		uint				getGrade( void ) const;
		std::string	const &	getName( void ) const;
		
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