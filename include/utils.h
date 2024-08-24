#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

const double EPS = 1e-9;

bool CompareEqual(double a, double b);
bool CompareMore(double a, double b);

#endif // UTILS_H_INCLUDED
