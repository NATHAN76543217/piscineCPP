#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{

	public:

		MutantStack(): std::stack<T>()
		{}
		MutantStack( MutantStack const & src ) :std::stack<T>(src)
		{} 
		~MutantStack()
		{}

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator	begin( void )
		{
			return this->c.begin();
		}
		
		iterator	end( void )
		{
			return this->c.end();
		}

	private:

};

#endif /* ***************************************************** MUTANTSTACK_H */