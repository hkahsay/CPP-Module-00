/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:25:07 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/29 13:40:09 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"iter.hpp"

int		main()
{
	std::string str[3];
	str[0] = "hello";
	str[1] = "world";
	str[2] = "2023";
	std::string strArray[] = { "Hello", "World", "C++","2023" };
	int	intArray[] = {1,2,3,4,5};
	size_t	len = 3;
	size_t	size = 4;
	size_t	intSize = 4;
	
	float	 array[3] = {1.2,2.6,3.9};
	iter(array, len, printValue<float>);
	std::cout<<std::endl;
	iter(str, len, printValue<std::string>);
	std::cout<<std::endl;
	iter(strArray, size, printValue<std::string>);
	std::cout<<std::endl;
	iter(intArray, intSize, printValue<int>);


	return 0;

}
