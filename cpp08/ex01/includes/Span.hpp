#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

class Span
{
	class SpanFullException : public std::exception
	{
		virtual const char *what(void ) const throw()
		{
			return "Span is already full";
		}
	};

	class NotSpannableException : public std::exception
	{
		virtual const char *what(void ) const throw()
		{
			return "Span is not spannable";
		}
	};

	public:

		Span();
		Span( uint N );
		Span( std::vector<int>::const_iterator start, std::vector<int>::const_iterator end );
		Span( Span const & src );
		~Span();

		Span &		operator=( Span const & rhs );

		uint	getSize( void ) const;

		void	addNumber(int number);
		int		shortestSpan( void );
		int		longestSpan( void );
		bool	spannable( void ) const;

	private:
		std::vector<int>	_values;
		uint				_limit;

};

std::ostream &			operator<<( std::ostream & o, Span const & i );

#endif /* ************************************************************ SPAN_H */