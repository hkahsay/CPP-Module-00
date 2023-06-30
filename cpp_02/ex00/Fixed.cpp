#include"Fixed.hpp"

const int Fixed:: j = 0;

Fixed:: Fixed(void): _fixFloatNbr(0) {
	std:: cout << "Default constructor called" << std:: endl;
	return ;
}

Fixed :: Fixed(int const n): _fixFloatNbr(n) {
	std:: cout << "Parametric constructor called" << std:: endl;
	return;
}
Fixed :: Fixed(Fixed const & src) {
	std:: cout << "copy constructor called"<< std:: endl;
	_fixFloatNbr = src._fixFloatNbr;
	return ;
}
Fixed:: ~Fixed() {
	std:: cout <<" Destructor called" << std:: endl;
}

Fixed& Fixed::operator=(const Fixed& src) {
    // Copy assignment operator implementation
    if (this != &src) {
        _fixFloatNbr = src._fixFloatNbr;
    }
    return *this;
}

int Fixed:: getRawBits()const {
	return _fixFloatNbr;

}

void Fixed:: setRawBits(int const raw) {
	_fixFloatNbr = raw;
	return;
}

std::ostream& operator<<(std::ostream& o, Fixed const& i) {
    // Overloaded insertion operator implementation
    o << i.getRawBits();
    return o;
}