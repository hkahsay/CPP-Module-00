#include <iostream>
#include "Fixed.hpp"

int main( void ) {

	Fixed a(3.3f);
	Fixed b(3);
	// Fixed b( a );
	// Fixed c;

	// c = b;

	std::cout <<  std::bitset<32>(a.getRawBits()) << std::endl;
	std::cout <<  std::bitset<32>(b.getRawBits()) << std::endl;
	// std::cout << b.getRawBits() << std::endl;
	// std::cout << c.getRawBits() << std::endl;

	return 0;
}
