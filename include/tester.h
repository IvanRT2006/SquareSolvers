#ifndef TESTER_H_INCLUDED
#define TESTER_H_INCLUDED

#include <stdio.h>
#include "solvers.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct SolveTester
{
    double a;
    double b;
    double c;
    double x1expected;
    double x2expected;
    NumberRoots num_roots;
};

int Tester(struct SolveTester *ST);

#endif // TESTER_H_INCLUDED
