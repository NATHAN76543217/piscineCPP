#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>

class Span
{
	class SpanFullException : public std::exception
	{
		virtual const char *what(void ) const throw()
		{
			return "Span is already full";
		}
	};

	public:

		Span();
		Span( uint N );
		Span( Span const & src );
		~Span();

		Span &		operator=( Span const & rhs );

		uint	getSize( void ) const;

		void	addNumber(int number);
		int		shortestSpan( void ) const;
		int		longestSpan( void ) const;
	private:
		int		*_values;
		uint	_size;

};

std::ostream &			operator<<( std::ostream & o, Span const & i );

#endif /* ************************************************************ SPAN_H */