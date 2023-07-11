#include"Fixed.hpp"
#include<bitset>
#include<cmath>

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

Fixed:: Fixed(const float nbr): _fixFloatNbr(roundf(nbr * (1 << _NbrFractionalBits))) {
	// std::cout << "Float constructor called" << std::endl;
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

Fixed Fixed:: operator + (const Fixed& other)const {
	// Fixed result;
	// result._fixFloatNbr = _fixFloatNbr + other._fixFloatNbr;
	// return result;
	return Fixed(_fixFloatNbr + other._fixFloatNbr);

}

Fixed Fixed:: operator - (const Fixed& other)const {
	// Fixed result;
	// result._fixFloatNbr = _fixFloatNbr + other._fixFloatNbr;
	// return result;
	return Fixed(_fixFloatNbr + other._fixFloatNbr);
}

Fixed Fixed:: operator * (const Fixed& other)const {

	return Fixed(_fixFloatNbr * other._fixFloatNbr);
}

Fixed Fixed:: operator / (const Fixed& other)const {

	return Fixed(_fixFloatNbr / other._fixFloatNbr);
}

Fixed Fixed:: operator ++(void){
	++this->_fixFloatNbr;
	return *this;

}

Fixed Fixed:: operator ++(int){
	this->_fixFloatNbr++;
	return *this;
}

Fixed Fixed:: operator --(void){
	--this->_fixFloatNbr;
	return *this;
}

Fixed Fixed:: operator --(int){
	this->_fixFloatNbr--;
	return*this;
}


Fixed const& Fixed:: min( Fixed  const & a, Fixed const& b) {
	if (a <= b)
		return(a);
	return(b);
	
	
}

Fixed& Fixed:: min(Fixed & a, Fixed & b) {
	if (a < b)
		return(a);
	return(b);
}

Fixed& Fixed:: max( Fixed & a, Fixed & b) {
	if (a > b)
		return(a);
	return(b);
	
}

Fixed const & Fixed:: max(const Fixed & a, const Fixed & b) {
	if (a >= b)
		return(a);
	return(b);
	
}