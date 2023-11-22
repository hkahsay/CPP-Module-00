/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:24:57 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/21 11:24:58 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include<iostream>
#include<string>


template<typename T>
void	swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<typename T>
T	min(T &a, T &b)
{
	return(a < b)? a : b;
}

template<typename T>
T	max(T &a, T &b)
{
	return(a > b)? a : b;
}

#endif