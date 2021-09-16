#include <vector>
#include <list>
#include <stack>
#include <string>
#include <iostream>
#include "MutantStack.hpp"
#include "test.tpp"

void	testList()
{
	std::list<int> mlist;
	mlist.push_front(5);
	mlist.push_front(17);
	std::cout << "top: "<< mlist.front() << std::endl;
	mlist.pop_front();
	std::cout << "size: " << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737); //[...] mlist.push(0);
	std::list<int>::iterator it = mlist.begin();
	std::list<int>::iterator ite = mlist.end();
	++it;
	--it;
	while (it != ite)
	{
	    std::cout << *it << std::endl;
		++it; 
	}
	// std::stack<int> s(mlist);
}

void	testMutant()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737); //[...] mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	    std::cout << *it << std::endl;
		++it; 
	}
	std::stack<int> s(mstack);
}

int main()
{
	std::cout << "--with list--" << std::endl;
	testList();
	std::cout << "--with MutantStack--" << std::endl;
	testMutant();
	return 0;
}