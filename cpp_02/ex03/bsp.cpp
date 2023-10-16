#include"Point.hpp"
#include"Fixed.hpp"


bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed ax = a.getx();
    Fixed ay = a.gety();

	Fixed bx = b.getx();
    Fixed by = b.gety();

	Fixed cx = c.getx();
    Fixed cy = c.gety();

    // Fixed d1 = (bx - ax) * (point._y - a._y) - (by - a._y) * (point._x - a._x);
    // Fixed d2 = (c._x - b._x) * (point._y - b._y) - (c._y - b._y) * (point._x - b._x);
    // Fixed d3 = (a._x - c._x) * (point._y - c._y) - (a._y - c._y) * (point._x - c._x);



    Fixed d1 = (bx - ax) * Fixed(point.gety() - ay) - (by - ay) * Fixed(point.getx() - ax);
    Fixed d2 = (cx - bx) * Fixed(point.gety() - by) - (cy - by) * Fixed(point.getx() - bx);
    Fixed d3 = (ax - cx) * Fixed(point.gety() - cy) - (ay - cy) * Fixed(point.getx() - cx);

    // bool hasNegative = (d1 < 0) || (d2 < 0) || (d3 < 0);
    // bool hasPositive = (d1 > 0) || (d2 > 0) || (d3 > 0);

	bool hasNegative = (d1 < Fixed(0)) || (d2 < Fixed(0)) || (d3 < Fixed(0));
    bool hasPositive = (d1 > Fixed(0)) || (d2 > Fixed(0)) || (d3 > Fixed(0));

    return !(hasNegative && hasPositive);
}
