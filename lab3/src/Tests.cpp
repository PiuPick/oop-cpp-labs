#include "../include/Tests.h"
#include "../include/Functions.h"
#include <iostream>

using namespace std;

void testL1()
{
    cout << "\n[Тест L1 — проверка коллинеарности]\n";

    Point pts[] = {
        Point(0, 0),
        Point(1, 1),
        Point(2, 2)
    };

    printPoints(pts, 3);

    cout << "Ожидаемый результат: точки лежат на одной прямой\n";
    cout << "Фактический результат: "
        << (inLine(pts, 3) ? "точки лежат на одной прямой\n" : "точки НЕ лежат на одной прямой\n");
}


void testP1()
{
    cout << "\n[Тест P1 — максимум точек в окружности]\n";

    Point pts[] = {
        Point(0, 0),
        Point(1, 0),
        Point(0, 1),
        Point(5, 5)
    };

    double R = 1.5;

    printPoints(pts, 4);
    cout << "Радиус R = " << R << "\n";

    Point p = getMaxCirclePoint(pts, 4, R);

    cout << "Ожидаемый центр: около (0, 0)\n";
    cout << "Фактический центр: ";
    printPoint(p);
    cout << "\n";
}

void testF2()
{
    cout << "\n[Тест F2 — создание трапеции]\n";

    Point pts[] = {
        Point(0, 0),
        Point(4, 0),
        Point(3, 2),
        Point(1, 2)
    };

    printPoints(pts, 4);

    Trapeze t;
    if (getFigure(pts, t))
    {
        cout << "Результат: трапеция создана корректно\n";
        printTrapezeInfo(t);
    }
    else
    {
        cout << "Ошибка: фигура не создана\n";
    }
}

void runAllTests()
{
    testL1();
    testP1();
    testF2();
}
