#include <windows.h>
#include <iostream>

#include "include/Functions.h"
#include "include/Tests.h"

using namespace std;

bool inputPoints(Point* points, int count);

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "=== Практическая работа №3 ===\n";
    cout << "Вариант V = (10 * int('P') + int('L')) % 12 = " << (10 * int('P') + int('L')) % 12 << "\n";
    cout << "Вариант: 0 (Point, Trapeze | L1, P1, F2)\n";

    bool isRunning = true;

    while (isRunning)
    {
        cout << "\nМеню:\n";
        cout << "1. Проверка, лежат ли точки на одной прямой (L1)\n";
        cout << "2. Найти точку с максимумом точек в радиусе R (P1)\n";
        cout << "3. Создать трапецию по 4 точкам (F2)\n";
        cout << "4. Тестовый сценарий\n";
        cout << "0. Выход\n";
        cout << "> Ваш выбор: ";

        char choice;
        cin >> choice;

        switch (choice)
        {
        case '1':
            {
                int n;
                cout << "Введите количество точек: ";
                if (!(cin >> n) || n <= 0)
                {
                    cout << "Некорректное количество точек\n";
                    break;
                }

                Point* pts = new Point[n];
                if (!inputPoints(pts, n))
                {
                    cout << "Ошибка ввода точек\n";
                    delete[] pts;
                    break;
                }

                printPoints(pts, n);
                cout << (inLine(pts, n)
                             ? "Все точки лежат на одной прямой\n"
                             : "Точки не лежат на одной прямой\n");

                delete[] pts;
                break;
            }

        case '2':
            {
                int n;
                cout << "Введите количество точек: ";
                if (!(cin >> n) || n <= 0)
                {
                    cout << "Некорректное количество точек\n";
                    break;
                }

                Point* pts = new Point[n];
                if (!inputPoints(pts, n))
                {
                    cout << "Ошибка ввода точек\n";
                    delete[] pts;
                    break;
                }

                double R;
                cout << "Введите радиус R: ";
                if (!(cin >> R) || R < 0)
                {
                    cout << "Некорректный радиус\n";
                    delete[] pts;
                    break;
                }

                printPoints(pts, n);
                cout << "Радиус R = " << R << "\n";

                Point p = getMaxCirclePoint(pts, n, R);

                cout << "Результирующая точка: ";
                printPoint(p);
                cout << "\n";

                delete[] pts;
                break;
            }

        case '3':
            {
                Point pts[4];
                if (!inputPoints(pts, 4))
                {
                    cout << "Ошибка ввода точек\n";
                    break;
                }

                Trapeze t;
                printPoints(pts, 4);

                if (getFigure(pts, t))
                {
                    cout << "Трапеция создана\n";
                    printTrapezeInfo(t);
                }
                else
                    cout << "Ошибка: точки должны быть уникальны\n";

                break;
            }

        case '4':
            runAllTests();
            break;

        case '0':
            isRunning = false;
            break;

        default:
            cout << "Неизвестная команда\n";
        }

        if (!cin)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ошибка ввода\n";
        }
    }

    return 0;
}

bool inputPoints(Point* points, int count)
{
    for (int i = 0; i < count; ++i)
    {
        cout << "Введите точку " << i + 1 << " (x y): ";
        double x, y;
        if (!(cin >> x >> y))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            return false;
        }
        points[i] = Point(x, y);
    }
    return true;
}
