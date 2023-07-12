#include"Fixed.hpp"
#include<bitset>
#include<cmath>

// const  int _NbrFractionalBits = 8;

Fixed:: Fixed(void): _fixFloatNbr(0) {
	// std:: cout << "Default constructor called" << std:: endl;
	return ;
}

Fixed :: Fixed(int const n): _fixFloatNbr(n << _NbrFractionalBits) {
	// std:: cout << "Int constructor called" << std:: endl;
	return;

}

Fixed :: Fixed(Fixed const & src) {
	// std:: cout << "copy constructor called"<< std:: endl;
	*this = src;
	return;
}

Fixed:: Fixed(const float nbrf): _fixFloatNbr(roundf(nbrf * (1 << _NbrFractionalBits))) {
	//conversion is performed by multiplying nbrf by the scaling 
	//factor (1 << _NbrFractionalBits) 
	//and rounding the result to the nearest integer using roundf function.
}

Fixed:: ~Fixed() {
	// std:: cout <<" Destructor called" << std:: endl;
}

int Fixed:: getRawBits()const {
	// std:: cout<< "getRawBits member function called" << std:: endl;
	return _fixFloatNbr;

}

void Fixed:: setRawBits(int const raw) {
	_fixFloatNbr = raw;
	return;
}

Fixed& Fixed::operator=(const Fixed& rhs) {
	// std::cout << "Copy assignment operator called" << std::endl;
    // Copy assignment operator implementation
    if (this != &rhs) {
        _fixFloatNbr = rhs.getRawBits();
    }
    return *this;
}

float Fixed:: toFloat(void)const {
	return ((float)(_fixFloatNbr * (1.0f / (1 << Fixed::_NbrFractionalBits))));
	// It performs the reverse conversion of _fixFloatNbr back to a float value. 
	// It does this by dividing _fixFloatNbr by 
	// the scaling factor (1 << Fixed::_NbrFractionalBits) and 
	// casting the result to a float
}

int Fixed:: toInt(void) const {
	return (_fixFloatNbr >> Fixed:: _NbrFractionalBits);

}


std::ostream& operator<<(std::ostream& o, Fixed const& rhs) {
    // Overloaded insertion operator implementation
    o << rhs.toFloat();
    return o;
}

bool Fixed:: operator > (const Fixed& other)const {
	return (toFloat() > other.toFloat());
}

bool Fixed:: operator < (const Fixed& other) const {
	return(toFloat() < other.toFloat());
}

bool Fixed:: operator >= (const Fixed& other)const {
	return(toFloat() >= other.toFloat());
}

bool Fixed:: operator <= (const Fixed& other)const {
	return(toFloat() <= other.toFloat());
}

bool Fixed:: operator == (const Fixed& other)const {
	return(toFloat() == other.toFloat());
}

bool Fixed:: operator != (const Fixed& other)const {
	return(toFloat() != other.toFloat());
}

Fixed Fixed:: operator + (Fixed const & other) {
	Fixed result;
	result._fixFloatNbr = _fixFloatNbr + other._fixFloatNbr;
	return result;
	// return Fixed(_fixFloatNbr + other._fixFloatNbr);

}

// Fixed Fixed:: operator - (Fixed const & other)const {
// 	Fixed result;
// 	result = _fixFloatNbr - other._fixFloatNbr;
// 	return result;
// 	// return Fixed(_fixFloatNbr - other._fixFloatNbr);
// }

Fixed Fixed:: operator-(int value) const {
    Fixed result;
    result._fixFloatNbr = _fixFloatNbr - (value << _NbrFractionalBits);
    return result;
}

Fixed Fixed:: operator * (Fixed const & other) {

	Fixed result;
	result = this->toFloat() * other.toFloat();
	return result;
	// return Fixed(_fixFloatNbr * other._fixFloatNbr);
}

Fixed Fixed:: operator / (Fixed const & other) {

	return Fixed(toFloat() / other.toFloat());
}

Fixed Fixed:: operator ++(void){
	++this->_fixFloatNbr;
	return *this;

}

Fixed Fixed:: operator ++(int){
	Fixed temp(*this);
	this->_fixFloatNbr++;
	return temp;;
}

Fixed Fixed:: operator --(void){
	--this->_fixFloatNbr;
	return *this;
}

Fixed Fixed:: operator --(int){
	Fixed	temp(*this);
	this->_fixFloatNbr--;
	return temp;
}


Fixed const& Fixed:: min( Fixed  const & a, Fixed const& b) {
	if (a <= b)
		return(a);
	else
		return(b);
	
	
}

Fixed& Fixed:: min(Fixed & a, Fixed & b) {
	if (a < b)
		return(a);
	else
		return(b);
}

Fixed& Fixed:: max( Fixed & a, Fixed & b) {
	if (a > b)
		return(a);
	else
		return(b);
	
}

Fixed const & Fixed:: max(const Fixed & a, const Fixed & b) {
	if (a >= b)
		return(a);
	else
		return(b);
	
}