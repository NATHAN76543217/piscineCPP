#ifndef ARRAY_TPP
# define ARRAY_TPP
# include <iostream>

template< typename T>
class Array
{
	public:
		class OutOfBound : public std::exception
		{
			virtual const char * what() const throw ()
			{
				return "Index out of bound.";
			}
		};

		Array();
		Array(unsigned int i);
		Array(Array & src);
		~Array();

		Array<T>	&operator=(Array<T> const & rhs);
		T			&operator[](size_t idx);
		T const		&operator[](size_t idx) const;

		size_t		size(void) const;
	private:
		T*		_array;
		size_t	_size;
};

template<typename T>
Array<T>::Array()
{
	this->_array = new T[0]();
	this->_size = 0;
}

template<typename T>
Array<T>::Array(unsigned int i)
{
	this->_array = new T[i]();
	this->_size = i;
}

template<typename T>
Array<T>::Array(Array & src)
{
	this->_array = new T[src._size];
	for (size_t i = 0; i < src.size(); i++)
	{
		this->_array[i] = src._array[i];
	}
	this->_size = src._size;
}

template<typename T>
Array<T>::~Array()
{
	delete[] this->_array;
}

template<typename T>
Array<T>	&Array<T>::operator=(Array const & rhs)
{
	if (this != &rhs)
	{
		delete this->_array;
		this->_array = new T[rhs._size];
		for (size_t i = 0; i < rhs._size; i++)
			this->_array[i] = rhs[i];
		this->_size = rhs._size; 
	}
	return *this;
}

template<typename T>
T		&Array<T>::operator[](size_t idx)
{
	if (idx < 0 || idx >= this->_size)
		throw Array::OutOfBound();
	return this->_array[idx];
}

template<typename T>
T const		&Array<T>::operator[](size_t idx) const
{
	if (idx < 0 || idx >= this->_size)
		throw Array<T>::OutOfBound();
	return this->_array[idx];
}

template<typename T>
size_t		Array<T>::size(void) const
{
	return this->_size;
}

template<typename T>
std::ostream &operator<<(std::ostream & o, Array<T> array)
{
	o << "[";
	for (size_t i = 0; i < array.size(); i++)
	{
		o << array[i];
		if (i < array.size() - 1)
			o << ", ";
	}
	o << "]";
	return o;
}

#endif          //ARRAY_TPP