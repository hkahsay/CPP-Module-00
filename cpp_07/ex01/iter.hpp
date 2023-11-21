/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:25:03 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/21 11:25:04 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include<iostream>

template<typename T, typename Func>
void	iter(T *arr, size_t len, Func func)
{
	for (size_t i = 0; i < len; i++)
	{
		func(arr[i]);
	}
}

template<typename T>
void	printValue(T value)
{
	std::cout <<value<<std::endl;
}

#endif