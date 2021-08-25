#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>
# include <string>


class Karen
{
	typedef void (Karen::*Level)(void) const;

	public:

		Karen();
		~Karen();

		void complain( std::string level) const;

	private:
		Level _level[4];
		static const std::string _levelNames[4];
		
		void debug( void ) const;
		void info( void ) const;
		void warning( void ) const;
		void error( void ) const;
};

#endif /* *********************************************************** KAREN_H */