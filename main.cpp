#include "TxLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

enum SolverErrors
{
    UNDEFINED_NUMBER_ROOTS = -1000,
    NO_SOLVER_ERRORS = 0,
    READING_ERROR = 100,
};

#define GET_ERROR_STRING(error)               \
    if (error != NO_SOLVER_ERRORS)            \
    {                                         \
        printf("error number %d\n", error);   \
    }

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
SolverErrors GetAnswer(double x1, double x2, NumberRoots num_roots);
SolverErrors InputCoeff(double *coeff);
void Solver(double a, double b, double c, double x1, double x2);

int main()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    printf("Enter the coefficients:\n");

    GET_ERROR_STRING(InputCoeff(&a));
    GET_ERROR_STRING(InputCoeff(&b));
    GET_ERROR_STRING(InputCoeff(&c));

    Solver(a, b, c, x1, x2);

    return 0;
}

void Solver(double a, double b, double c, double x1, double x2)
{
    NumberRoots num_roots = NO_ROOTS;

    if (CompareEqual(a, 0) == true)
    {
        num_roots = SolverLinearEquation(b, c, &x1);
    }
    else
    {
        num_roots = SolverQuadroEquation(a, b, c, &x1, &x2);
    }

    GetAnswer(x1, x2, num_roots);

    printf("Program ended\n");
}

SolverErrors InputCoeff(double *coeff)
{
    int counts_not_error = 0;

    while (scanf("%lf", coeff) != 1)
    {
        int ch = 0;

        while (ch = getchar() != '\n' && ch != EOF)
        {
        }

    counts_not_error++;

    if(counts_not_error == 3)
    {
        return READING_ERROR;
    }

    printf("Your symbol isn't correct. Try again\n");

    }

    return NO_SOLVER_ERRORS;
}

SolverErrors GetAnswer(double x1, double x2, NumberRoots num_roots)
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
        default:
            return UNDEFINED_NUMBER_ROOTS;
            break;
    }

    return NO_SOLVER_ERRORS;

}

NumberRoots SolverLinearEquation(double b, double c, double *x1)
{
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x1 != NULL);

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
        *x1 = -c / b;
        return ONE_ROOT;
    }
}

NumberRoots SolverQuadroEquation(double a, double b, double c, double *x1, double *x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

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
