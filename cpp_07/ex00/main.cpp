/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkahsay <hkahsay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:24:42 by hkahsay           #+#    #+#             */
/*   Updated: 2023/11/29 12:12:21 by hkahsay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"

int main( void ) {
	int a = 2;
	int b = 3;
	float f = 0.2f;
	float f1 = 1.2f;
	double	d = 5.6;
	double	d1 = 6.6;
	
	std::cout<< std::endl;
	std::string c = "hello";
	std::string w = "world";
	
	std::cout << "before swap value c = " << c << ", before swap value w = " << w << std::endl;
	::swap(c, w);
	std::cout<<"after swap"<< std::endl;
	std::cout << "c = " << c << ", w = " << w << std::endl;
	std::cout << "min( c, w ) = " << ::min( c, w ) << std::endl;
	std::cout << "max( c, w ) = " << ::max( c, w ) << std::endl;
	std::cout<< std::endl;
	
	std::cout << "before swap value a = " << a << ", before swap value b = " << b << std::endl;
	::swap( a, b );
	std::cout<<"after swap"<< std::endl;
	
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::cout<< std::endl;
	
	std::cout << "before swap value f= " << f<< ", before swap value f1 = " << f1 << std::endl;
	::swap( f, f1 );
	std::cout<<"after swap"<< std::endl;
	std::cout << "f = " << f << ", f1 = " << f1 << std::endl;
	std::cout << "min( f, f1 ) = " << ::min(f, f1) << std::endl;
	std::cout << "max(f, f1  ) = " << ::max(f, f1) << std::endl;
	std::cout<< std::endl;
	
	std::cout << "before swap value d = " << d << ", before swap value d1 = " << d1 << std::endl;
	::swap( d, d1 );
	std::cout<<"after swap"<< std::endl;
	std::cout << "d = " << d << ", d1 = " << d1 << std::endl;
	std::cout << "min( d, d1 ) = " << ::min(d, d1) << std::endl;
	std::cout << "max( d, d1 ) = " << ::max(d, d1) << std::endl;

	return 0;
}