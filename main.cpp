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

const double EPS = 1e-9;

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
bool CompareEqual(double a, double b);
bool CompareMore(double a, double b);
SolverErrors GetAnswer(struct squares *x1x2, NumberRoots num_roots);
SolverErrors InputCoeff(double *coeff);
void Solver(struct coefficients *abc, struct squares *x1x2, NumberRoots *num_roots);

int main()
{
    struct coefficients abc = {0,0,0};
    struct squares x1x2 = {0,0};

    NumberRoots num_roots = NO_ROOTS;

    printf("Enter the coefficients:\n");

    GET_ERROR_STRING(InputCoeff(&(abc.a)));
    GET_ERROR_STRING(InputCoeff(&(abc.b)));
    GET_ERROR_STRING(InputCoeff(&(abc.c)));

    Solver(&abc, &x1x2,&num_roots);
    GetAnswer(&x1x2, num_roots);

    printf("Program ended\n");

    return 0;
}

void Solver(struct coefficients *abc, struct squares *x1x2, NumberRoots *num_roots)
{
    if (CompareEqual(abc->a, 0) == true)
    {
        *num_roots = SolverLinearEquation(abc, x1x2);
    }
    else
    {
        *num_roots = SolverQuadroEquation(abc, x1x2);
    }
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

SolverErrors GetAnswer(struct squares *x1x2, NumberRoots num_roots)
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
            printf("Two roots: x1 = %lf, x2 = %lf\n", x1x2->x1, x1x2->x2);
            break;
        case ONE_ROOT:
            printf("Only one root: x1 = %lf\n", x1x2->x1);
            break;
        default:
            return UNDEFINED_NUMBER_ROOTS;
            break;
    }

    return NO_SOLVER_ERRORS;

}

NumberRoots SolverLinearEquation(struct coefficients *abc, struct squares *x1x2)
{
    assert(isfinite(abc->b));
    assert(isfinite(abc->c));
    assert(x1x2 != NULL);
    assert(abc != NULL);

    if (CompareEqual(abc->b, 0) == true)
    {
        if (CompareEqual(abc->c, 0) == true)
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
        (x1x2->x1) = -(abc->c) / (abc->b);
        return ONE_ROOT;
    }
}

NumberRoots SolverQuadroEquation(struct coefficients *abc, struct squares *x1x2)
{
    assert(x1x2 != NULL);
    assert(abc != NULL);
    assert(isfinite(abc->a));
    assert(isfinite(abc->b));
    assert(isfinite(abc->c));

    const double D = (abc->b) * (abc->b) - 4 * (abc->a) * (abc->c);

    if (CompareEqual(D, 0) == true)
    {
         (x1x2->x1) = (x1x2->x2) = -(abc->b) / (2 * (abc->a));
         return ONE_ROOT;
    }
    else
    {
        if (CompareMore(D, 0) == true)
        {
            (x1x2->x1) = (-(abc->b) + sqrt(D)) / (2 * (abc->a));
            (x1x2->x2) = (-(abc->b) - sqrt(D)) / (2 * (abc->a));
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
    if (fabs(a - b) < EPS)
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
    if ((a - b) > EPS)
    {
        return true;
    }
    else
    {
        return false;
    }
}
