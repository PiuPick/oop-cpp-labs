#include "matrix.h"

// Освобождение памяти для матрицы
void freeMatrix(Matrix& m)
{
    if (!m.data)
        return;

    for (int i = 0; i < m.rows; ++i)
        delete[] m.data[i];

    delete[] m.data;
    m.data = nullptr;
    m.rows = 0;
    m.cols = 0;
}

// Выделение памяти для матрицы
bool allocateMatrix(Matrix& m, int rows, int cols)
{
    if (rows <= 0 || cols <= 0)
        return false;

    freeMatrix(m);

    m.rows = rows;
    m.cols = cols;
    m.data = new int*[rows];
    for (int i = 0; i < rows; ++i)
        m.data[i] = new int[cols];

    return true;
}

// Ввод матрицы с консоли
bool inputMatrix(Matrix& m)
{
    if (!m.data)
        return false;

    for (int i = 0; i < m.rows; ++i)
        for (int j = 0; j < m.cols; ++j)
            if (!(cin >> m.data[i][j]))
            {
                cin.clear();
                cin.ignore(10000, '\n');
                return false;
            }
    return true;
}

// Вывод матрицы в консоль
void printMatrix(const Matrix& m)
{
    if (!m.data)
    {
        cout << "Matrix is empty\n";
        return;
    }

    for (int i = 0; i < m.cols; ++i)
    {
        for (int j = 0; j < m.rows; ++j)
            cout << m.data[i][j] << " ";
        cout << endl;
    }
}

// Умножение матриц A и B, результат в C
bool multiplyMatrices(const Matrix& A, const Matrix& B, Matrix& C)
{
    if (!A.data || !B.data ||
        A.cols != B.rows)
        return false;

    if (!allocateMatrix(C, A.rows, B.cols))
        return false;

    for (int i = 0; i < A.rows; ++i)
        for (int j = 0; j < B.cols; ++j)
        {
            long long sum = 0;
            for (int k = 0; k < A.cols; ++k)
                sum += A.data[i][k] * B.data[k][j];
            C.data[i][j] = sum;
        }

    return true;
}

// Тестовый сценарий
void testScenario()
{
    Matrix A, B, C;

    allocateMatrix(A, 2, 2);
    allocateMatrix(B, 2, 2);

    A.data[0][0] = 1;
    A.data[0][1] = 2;
    A.data[1][0] = 3;
    A.data[1][1] = 4;

    B.data[0][0] = 5;
    B.data[0][1] = 6;
    B.data[1][0] = 7;
    B.data[1][1] = 8;

    cout << "Matrix A:\n";
    printMatrix(A);

    cout << "Matrix B:\n";
    printMatrix(B);

    cout << "A * B:\n";
    printMatrix(C);

    freeMatrix(A);
    freeMatrix(B);
    freeMatrix(C);
}
