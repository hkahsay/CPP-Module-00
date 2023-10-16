#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"


int main() {
    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(2.0f, 4.0f);
    Point point1(1.0f, 1.0f);  // Inside the triangle
    Point point2(3.0f, 3.0f);  // Inside the triangle
    Point point3(5.0f, 5.0f);  // Outside the triangle

    bool result1 = bsp(a, b, c, point1);
    bool result2 = bsp(a, b, c, point2);
    bool result3 = bsp(a, b, c, point3);

    std::cout << "Point 1 inside triangle: " << std::boolalpha << result1 << std::endl;
    std::cout << "Point 2 inside triangle: " << std::boolalpha << result2 << std::endl;
    std::cout << "Point 3 inside triangle: " << std::boolalpha << result3 << std::endl;

    return 0;
}
