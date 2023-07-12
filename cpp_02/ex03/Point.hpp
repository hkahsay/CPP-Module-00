#ifndef POINT_HPP
#define POINT_HPP

#include<iostream>
#include <iomanip>
#include"Fixed.hpp"

class Point {

	private:

	Fixed const _x;
	Fixed const _y;

	static const  int _NbrFractionalBits = 8;

	public:

	Point(void);
	Point(float const& a, float const& b);
	Point(Point const & src);
	~Point(void);
	Point & operator = (const Point& rhs);
	int getx()const;
	int gety()const;
	// const Fixed& Point::getx()const;
	// const Fixed& Point::gety()const;

	// void setRawBits(int const raw);
};
	bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif