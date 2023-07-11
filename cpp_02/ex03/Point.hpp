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
	Point(float const a, float const b);
	Point(Point const & src);
	~Point(void);
	Point & operator = (const Point& rhs);
	int getRawBits()const;
	void setRawBits(int const raw);
	Point(const float nbr);
	bool bsp( Point const a, Point const b, Point const c, Point const point);
};

#endif