#ifndef ARRAY_HPP
#define ARRAY_HPP

#include<iostream>
#include<exception>

template<typename T>
class Array
{
	private:
		T	*_myArray;
		unsigned int	_n;
	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const &src);
		Array&	operator = (Array const & rhs);
		T& operator [] (unsigned int index);
		unsigned int	size()const;
		~Array();
};
// template<typename T>
// std::ostream&		operator<<(std::ostream& stream, const Array<T>& rhs);

#include "Array.tpp"

#endif
