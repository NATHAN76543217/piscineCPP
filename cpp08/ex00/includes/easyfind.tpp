#ifndef EASYFIND_TPP
# define EASYFIND_TPP
# include <algorithm>

template<typename T>
bool	easyfind(T cnt, int find) 
{
	typename T::const_iterator it;
	it = std::find(cnt.begin(), cnt.end(), find);
	return (it != cnt.end());
}

#endif	//EASYFIND_TPP
