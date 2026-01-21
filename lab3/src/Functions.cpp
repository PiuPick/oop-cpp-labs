#include "../include/Functions.h"
#include <iostream>
#include <cmath>

using namespace std;

// L1
bool inLine(Point points[], int size)
{
    if (size < 3) return true;

    double x1 = points[0].getX();
    double y1 = points[0].getY();
    double x2 = points[1].getX();
    double y2 = points[1].getY();

    const double EPS = 1e-9;

    for (int i = 2; i < size; ++i)
    {
        double x3 = points[i].getX();
        double y3 = points[i].getY();

        double area = (x2 - x1) * (y3 - y1) -
            (x3 - x1) * (y2 - y1);

        if (fabs(area) > EPS)
            return false;
    }
    return true;
}

// P1
Point getMaxCirclePoint(Point* points, int size, int R)
{
    if (size == 0) return Point();

    int maxCount = 0;
    Point result = points[0];

    for (int i = 0; i < size; ++i)
    {
        int count = 0;
        for (int j = 0; j < size; ++j)
        {
            double dx = points[i].getX() - points[j].getX();
            double dy = points[i].getY() - points[j].getY();
            double dist = sqrt(dx * dx + dy * dy);

            if (dist <= R) ++count;
        }

        if (count > maxCount)
        {
            maxCount = count;
            result = points[i];
        }
    }

    return result;
}

static bool areParallel(const Point& a, const Point& b,
                        const Point& c, const Point& d)
{
    double dx1 = b.getX() - a.getX();
    double dy1 = b.getY() - a.getY();
    double dx2 = d.getX() - c.getX();
    double dy2 = d.getY() - c.getY();

    return fabs(dx1 * dy2 - dy1 * dx2) < 1e-9;
}

// F2
bool getFigure(Point points[], Trapeze& figure)
{
    // проверка уникальности
    for (int i = 0; i < 4; ++i)
        for (int j = i + 1; j < 4; ++j)
            if (points[i].getX() == points[j].getX() &&
                points[i].getY() == points[j].getY())
                return false;

    // Проверка параллельности сторон
    int parallelCount = 0;

    if (areParallel(points[0], points[1], points[2], points[3])) ++parallelCount;
    if (areParallel(points[1], points[2], points[3], points[0])) ++parallelCount;
    if (areParallel(points[0], points[3], points[1], points[2])) ++parallelCount;
    if (areParallel(points[0], points[2], points[1], points[3])) ++parallelCount;

    // Для трапеции должно быть ровно 1 пара параллельных сторон
    if (parallelCount != 1)
        return false;

    figure = Trapeze(points[0], points[1], points[2], points[3]);
    return true;
}

void printPoint(const Point& p)
{
    cout << "(" << p.getX() << ", " << p.getY() << ")";
}

void printPoints(const Point points[], int size)
{
    cout << "Входные точки:\n";
    for (int i = 0; i < size; ++i)
    {
        cout << "  " << i + 1 << ". ";
        printPoint(points[i]);
        cout << "\n";
    }
}

void printTrapezeInfo(const Trapeze& t)
{
    auto pts = t.getPoints();

    cout << "Точки трапеции:\n";
    for (int i = 0; i < 4; ++i)
    {
        cout << "  " << i + 1 << ". ";
        printPoint(pts[i]);
        cout << "\n";
    }

    cout << "Периметр: " << t.getPerimeter() << "\n";
    cout << "Площадь: " << t.getArea() << "\n";
}
