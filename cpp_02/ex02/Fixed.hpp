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
	Fixed(const float nbr);
	float toFloat(void)const;
	int toInt(void) const;

	bool operator > (const Fixed& other)const;
	bool operator < (const Fixed& other) const;
	bool operator >= (const Fixed& other)const;
	bool operator <= (const Fixed& other)const;
	bool operator == (const Fixed& other)const;
	bool operator != (const Fixed& other)const;
	Fixed operator + (const Fixed& other)const;
	Fixed operator - (const Fixed& other)const;
	Fixed operator * (const Fixed& other)const;
	Fixed operator / (const Fixed& other)const;

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