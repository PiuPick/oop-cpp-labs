#pragma once
#include "Point.h"
#include "Trapeze.h"

bool inLine(Point points[], int size);
Point getMaxCirclePoint(Point* points, int size, int R);
bool getFigure(Point points[], Trapeze& figure);

void printPoint(const Point& p);
void printPoints(const Point points[], int size);
void printTrapezeInfo(const Trapeze& t);
