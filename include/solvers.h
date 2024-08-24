#ifndef SOLVERS_H_INCLUDED
#define SOLVERS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <windows.h>

enum ForegroundColour
{
    RED = FOREGROUND_RED,
    BLUE = FOREGROUND_BLUE,
    GREEN = FOREGROUND_GREEN,
    YELLOW = FOREGROUND_RED,
    BASE = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN,
};

enum SolverErrors
{
    UNDEFINED_NUMBER_ROOTS = -1000,
    NO_SOLVER_ERRORS = 0,
    READING_ERROR = 100,
};

enum NumberRoots
{
   INF_ROOTS = -1,
   NO_ROOTS,
   ONE_ROOT,
   TWO_ROOTS,
};

struct coefficients
{
    double a;
    double b;
    double c;
};

struct squares
{
    double x1;
    double x2;
};

NumberRoots SolverLinearEquation(struct coefficients *abc, struct squares *x1x2);
NumberRoots SolverQuadroEquation(struct coefficients *abc, struct squares *x1x2);
SolverErrors GetAnswer(struct squares *x1x2, NumberRoots num_roots);
NumberRoots Solver(struct coefficients *abc, struct squares *x1x2, NumberRoots *num_roots);
void Color(ForegroundColour colour);

#endif // SOLVERS_H_INCLUDED
