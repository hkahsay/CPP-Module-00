/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:25:23 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/21 11:25:50 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Array.hpp"

#define MAX_VALUE 10

int	main()
{
	std::cout<<"--------Empty array test--------\n";
	Array<int> empty;
	try//<< empty[0]
	{
		std::cout<< "access the value of empty array: "<<&empty <<std::endl<< " access empty[0]"<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout<<"--------test copy constructor int string and float --------\n";
	Array<int> arr(3);
	arr[1] = 5;
	Array<int> arr2(arr);
	arr[1] = 6;
	Array<float> fnbr(MAX_VALUE);
	fnbr[5]= 7.8f;
	Array<float> copyfnbr(fnbr);
	fnbr[5] = 10.7f;

	std::cout<<"arr.size():  " << arr.size()<< std::endl;
	std::cout<<"arr[1]:      " << arr[1]<< std::endl;
	std::cout<<"arr2.size(): " << arr2.size()<< std::endl;
	std::cout<<"arr2[1]:     " << arr2[1]<< std::endl;
	std::cout<<"fnbr.size():  " << fnbr.size()<< std::endl;
	std::cout<<"fnbr[5]:      " << fnbr[5]<< std::endl;
	std::cout<<"copyfnbr.size():  " << copyfnbr.size()<< std::endl;
	std::cout<<"copyfnbr[5]:      " << copyfnbr[5]<< std::endl;

	// std::cout<<"--------test assignment operator --------\n";
	// Array<int> arr3(3);
	// arr3[1] = 5;
	// Array<int> arr4(2);
	// arr4 = arr3;
	// arr3[1] = 6;

	// std::cout<<"arr3.size():  " << arr3.size()<< std::endl;
	// std::cout<<"arr3[1]:      " << arr3[1]<< std::endl;
	// std::cout<<"arr4.size():  " << arr4.size()<< std::endl;
	// std::cout<<"arr4[1]:      " << arr4[1]<< std::endl;



	return 0;
}