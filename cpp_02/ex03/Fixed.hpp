#ifndef Fixed_HPP
#define Fixed_HPP

#include<iostream>
#include <iomanip>



class Fixed {

	private:

	int	_fixFloatNbr;
	static const  int _NbrFractionalBits = 8;

	public:

	Fixed(void);// Default constructor
	Fixed(int const n);
	Fixed(Fixed const & src);
	~Fixed(void);
	Fixed & operator = (const Fixed& rhs);
	int getRawBits()const;
	void setRawBits(int const raw);
	Fixed(const float nbrf);
	float toFloat(void)const;
	int toInt(void) const;

	bool operator > (const Fixed& other)const;
	bool operator < (const Fixed& other) const;
	bool operator >= (const Fixed& other)const;
	bool operator <= (const Fixed& other)const;
	bool operator == (const Fixed& other)const;
	bool operator != (const Fixed& other)const;

	Fixed operator + (Fixed const & other);
	// Fixed operator - (Fixed const & other)const;
	Fixed operator-(int value) const;
	Fixed operator * (Fixed const & other);
	Fixed operator / (Fixed const & other);

	Fixed operator++(void);
	Fixed operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);

	static Fixed const& min( Fixed  const & a, Fixed const& b);
	static Fixed& min(Fixed & a, Fixed & b);
	static Fixed& max( Fixed & a, Fixed & b);
	static Fixed const& max(const Fixed & a, const Fixed & b);


};

std::ostream& operator<< (std:: ostream & o, Fixed const & rhs);
// std::ostream& operator<< (std:: ostream & o, Fixed const & i);
	
#endif

// a fixed-point number refers to a numeric representation 
// that has a fixed number of bits allocated for the fractional part 
// (decimal part) of the number. The integer part 
// and fractional part are combined into a single value, stored in the _fixFloatNbr


// the fixed-point number representation allows you to represent fractional values
//  with a fixed precision, similar to floating-point numbers but without 
//  the dynamic range and precision adjustments. It is often used in situations 
//  where exact decimal precision is required, such as financial calculations, 
// embedded systems, or when floating-point operations are not available or too costly.