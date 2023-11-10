#ifndef ARRAYT_HPP
#define ARRAYT_HPP

#include<iostream>
#include<exception>

template<typename T>
class Array
{
	private:
		unsigned int	_n;
		T	*_myArray;
	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const &src);
		Array&	operator = (Array const & rhs);
		T& operator [] (unsigned int index);
		// const T& operator [] (unsigned int index);
		unsigned int	size()const;
		~Array();
};
// template<typename T>
// std::ostream&		operator<<(std::ostream& stream, const Array<T>& rhs);

#include "arrayt.tpp"

#endif
