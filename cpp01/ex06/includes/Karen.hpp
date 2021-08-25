#ifndef KAREN_HPP
# define KAREN_HPP

# include <iostream>
# include <string>

#define NBR_LEVELS 4

class Karen
{
	typedef void (Karen::*Level)(void) const;

	public:

		Karen();
		~Karen();

		static int const nbr_levels;

		void complain( std::string level) const;
		static const std::string levelNames[NBR_LEVELS];

	private:
		Level _level[NBR_LEVELS];
		
		void debug( void ) const;
		void info( void ) const;
		void warning( void ) const;
		void error( void ) const;
};

#endif /* *********************************************************** KAREN_H */