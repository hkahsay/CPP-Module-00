/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:25:17 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/21 11:25:18 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

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
template<typename T>
std::ostream&		operator<<(std::ostream& stream, const Array<T>& rhs);

#include "Array.tpp"

#endif
