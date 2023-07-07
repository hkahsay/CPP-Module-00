#ifndef Fixed_HPP
#define Fixed_HPP

#include<iostream>
#include <iomanip>

class Fixed {

	private:

	int	_FixPointNbr;
	static const int NumFractionalBits = 8;

	public:

	Fixed(void);// Default constructor
	Fixed(int const n);
	Fixed(Fixed const & src);
	~Fixed(void);
	Fixed& operator = (const Fixed& src);
	int getRawBits()const;
	void setRawBits(int const raw);
};

std::ostream& operator<< (std:: ostream & o, Fixed const & i);
	
#endif