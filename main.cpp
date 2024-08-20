#include "TxLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

const double eps = 1e-9;

enum NumberRoots
{
   INF_ROOTS = -1,
   NO_ROOTS,
   ONE_ROOT,
   TWO_ROOTS,
};

NumberRoots SolverLinearEquation(double b, double c, double *x1);
NumberRoots SolverQuadroEquation(double a, double b, double c, double *x1, double *x2);
bool CompareEqual(double a, double b);
bool CompareMore(double a, double b);
NumberRoots GetAnswer(double x1, double x2, NumberRoots num_roots);
void InputCoeff(double *coeff);
void Solver();

int main()
{
    Solver();

    return 0;
}

void Solver()
{
    double a, b, c, x1 = 0, x2 = 0;
    NumberRoots num_roots = NO_ROOTS;

    printf("Enter the coefficients:\n");

    InputCoeff(&a);
    InputCoeff(&b);
    InputCoeff(&c);

    if (a == 0)
    {
        num_roots = SolverLinearEquation(b, c, &x1);
    }

    else
    {
        num_roots = SolverQuadroEquation(a, b, c, &x1, &x2);
    }

    GetAnswer(x1, x2, num_roots);

    printf("Program ended");
}

void InputCoeff(double *coeff)
{
    while (scanf("%lf", coeff) != 1)
    {
        int ch = 0;

        while (ch = getchar() != '\n' && ch != EOF)
        {
        }

    printf("Your symbol isn't correct. Try again\n");

    }
}

NumberRoots GetAnswer(double x1, double x2, NumberRoots num_roots)
{
    switch(num_roots)
    {
        case INF_ROOTS:
            printf("Solvers in this equation don't have borders\n");
            break;
        case NO_ROOTS:
            printf("Not solvers in this equation!\n");
            break;
        case TWO_ROOTS:
            printf("Two roots: x1 = %lf, x2 = %lf\n", x1, x2);
            break;
        case ONE_ROOT:
            printf("Only one root: x1 = %lf\n", x1);
            break;
    }
}

NumberRoots SolverLinearEquation(double b, double c, double *x1)
{
    NumberRoots num_roots = INF_ROOTS;

    if (CompareEqual(b, 0) == true)
    {
        if (CompareEqual(c, 0) == true)
        {
            return INF_ROOTS;
        }
        else
        {
            return NO_ROOTS;
        }
    }
    else
    {
        *x1 = -c/b;
        return ONE_ROOT;

    }
}

NumberRoots SolverQuadroEquation(double a, double b, double c, double *x1, double *x2)
{
    NumberRoots num_roots = INF_ROOTS;
    const double D = b * b - 4 * a * c;

    if (CompareEqual(D, 0) == true)
    {
         *x1 = *x2 = -b / (2 * a);
         return ONE_ROOT;
    }
    else
    {
        if (CompareMore(D, 0) == true)
        {
            *x1 = (-b + sqrt(D)) / (2 * a);
            *x2 = (-b - sqrt(D)) / (2 * a);
            return TWO_ROOTS;
        }
        else
        {
            return NO_ROOTS;
        }
    }
}

bool CompareEqual(double a, double b)
{
    if (fabs(a - b) < eps)
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool CompareMore(double a, double b)
{
    if ((a - b) > eps)
    {
        return true;
    }

    else
    {
        return false;
    }
}
