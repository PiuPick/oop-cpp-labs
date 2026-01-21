#include <windows.h>
#include "matrix.h"

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "=== Практическая работа №2 ===\n";

    cout << "Вариант V = int('P') % 8 = " << 'P' % 8 << "\n";
    cout << "Операция: Матричное умножение\n";

    bool isRunning = true;

    while (isRunning)
    {
        cout << "\nМеню:\n";
        cout << "1. Создать и заполнить матрицы\n";
        cout << "2. Показать матрицы\n";
        cout << "3. Умножить матрицы\n";
        cout << "4. Тестовый сценарий\n";
        cout << "0. Выход из программы\n";
        cout << "> Ваш выбор: ";

        Matrix A, B, C;
        char userChoice;
        cin >> userChoice;

        switch (userChoice)
        {
        case '1':
            {
                int r1, c1, r2, c2;

                cout << "Внесите количество строк и колонок матрицы A: ";
                if (!(cin >> r1 >> c1)) break;

                cout << "Внесите количество строк и колонок матрицы B: ";
                if (!(cin >> r2 >> c2)) break;

                if (allocateMatrix(A, r1, c1) &&
                    allocateMatrix(B, r2, c2))
                {
                    cout << "Ошибка выделения памяти для матриц\n";
                    freeMatrix(A);
                    freeMatrix(B);
                    break;
                }

                cout << "Заполните матрицу A:\n";
                if (!inputMatrix(A))
                {
                    cout << "Ошибка заполнения матрицы\n";
                    freeMatrix(A);
                    freeMatrix(B);
                    break;
                }

                cout << "Заполните матрицу B:\n";
                if (!inputMatrix(B))
                {
                    cout << "Ошибка заполнения матрицы\n";
                    freeMatrix(A);
                    freeMatrix(B);
                }
                break;
            }

        case '2':
            cout << "Матрица A:\n";
            printMatrix(A);
            cout << "Матрица B:\n";
            printMatrix(B);
            cout << "Результирующая матрица C:\n";
            printMatrix(C);
            break;

        case '3':
            freeMatrix(C);
            if (multiplyMatrices(A, B, C))
                cout << "Перемножение матриц выполнено\n";
            else
                cout << "Ошибка: не удалось выполнить перемножение матриц\n";
            break;

        case '4':
            testScenario();
            break;

        case '0':
            isRunning = false;
            freeMatrix(A);
            freeMatrix(B);
            freeMatrix(C);
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
