#pragma once

#include <iostream>
using namespace std;

struct Matrix
{
    int rows;
    int cols;
    int** data;

    Matrix() : rows(0), cols(0), data(nullptr)
    {
    }
};

void freeMatrix(Matrix& m);
bool allocateMatrix(Matrix& m, int rows, int cols);
bool inputMatrix(Matrix& m);
void printMatrix(const Matrix& m);
bool multiplyMatrices(const Matrix& A, const Matrix& B, Matrix& C);
void testScenario();