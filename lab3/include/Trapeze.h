#pragma once
#include "Point.h"
#include <array>
#include <cmath>
using namespace std;

class Trapeze
{
private:
    array<Point, 4> points;

public:
    Trapeze() = default;

    Trapeze(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
    {
        points = {p1, p2, p3, p4};
    }

    array<Point, 4> getPoints() const { return points; }

    double getDistance(const Point& a, const Point& b) const
    {
        double dx = a.getX() - b.getX();
        double dy = a.getY() - b.getY();
        return sqrt(dx * dx + dy * dy);
    }

    double getPerimeter() const
    {
        double p = 0;
        for (int i = 0; i < 4; ++i)
            p += getDistance(points[i], points[(i + 1) % 4]);
        return p;
    }

    // Формула площади Гаусса (формула шнурования или формула землемера) для произвольного многоугольника
    double getArea() const
    {
        double area = 0;
        for (int i = 0; i < 4; ++i)
        {
            area += (points[i].getX() * points[(i + 1) % 4].getY()) -
                (points[(i + 1) % 4].getX() * points[i].getY());
        }
        return abs(area) * 0.5;
    }
};