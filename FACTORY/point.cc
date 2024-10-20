#define _USE_MATH_DEFINES_
#include <iostream>
#include <memory>
#include <vector>
#include <cmath>

enum class PointType{
    Cartisian,
    Polar
};
class Point{
    // //
    // //
    // Point(double a, double b, PointType type = PointType::Cartisian) : x{x}, y{y} {}

    // private: 
    // double x, y;

    double x,y;

    Point(double x, double y) : x{x}, y{y} {}

    class PointFactory {
    public:
    static Point NewCartisian(double x, double y)
    {
        return {x,y};
    }
    static Point NewPolar(double r, double theta)
    {
        return {r*cos(theta), r*sin(theta)};
    }
};

    public:

    friend std::ostream& operator<<(std::ostream& out, Point& point)
    {
        return out << point.x << " " << point.y << std::endl;
    }

    static PointFactory factory;
};



int main()
{
    auto p = Point::factory.NewCartisian(2,3);
    auto p2 = Point::factory.NewPolar(2, M_PI_4);
    std::cout << p;
    std::cout << p2;
}