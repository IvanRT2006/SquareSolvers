#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <assert.h>
#include "..\include\solvers.h"
#include "..\include\utils.h"

#define ASSERT(x) \
    if (!x) \
        printf("assertion failed %s file(%s) line: %d", __func__, __FILE__, __LINE__); \



/**
    \file
    \brief Файл с выполнением функций по возвращению количества корней и вывода корней, а также
    функции по подсветке.
*/
NumberRoots Solver(struct coefficients *abc, struct squares *x1x2, NumberRoots *num_roots)
{
    if (CompareEqual(abc->a, 0) == true)
    {
        *num_roots = SolverLinearEquation(abc, x1x2);
    }
    else
    {
        *num_roots = SolverQuadroEquation(abc, x1x2);
    }

    return NO_ROOTS;
}

SolverErrors GetAnswer(struct squares *x1x2, NumberRoots num_roots)
{
    switch(num_roots)
    {
        case INF_ROOTS:
            Color(BLUE);
            printf("Solvers in this equation don't have borders\n");
            Color(BASE);
            getch();
            break;
        case NO_ROOTS:
            Color(RED);
            printf("Not solvers in this equation!\n");
            Color(BASE);
            getch();
            break;
        case TWO_ROOTS:
            Color(GREEN);
            printf("Two roots: x1 = %lf, x2 = %lf\n", x1x2->x1, x1x2->x2);
            Color(BASE);
            getch();
            break;
        case ONE_ROOT:
            Color(BLUE);
            printf("Only one root: x1 = %lf\n", x1x2->x1);
            Color(BASE);
            getch();
            break;
        default:
            return UNDEFINED_NUMBER_ROOTS;
            break;
    }

    return NO_SOLVER_ERRORS;

}

NumberRoots SolverLinearEquation(struct coefficients *abc, struct squares *x1x2)
{
    ASSERT(abc);
    ASSERT(isfinite(abc->b));
    ASSERT(isfinite(abc->c));
    ASSERT(x1x2);

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
    ASSERT(x1x2);
    ASSERT(abc);
    ASSERT(isfinite(abc->a));
    ASSERT(isfinite(abc->b));
    ASSERT(isfinite(abc->c));

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

void Color(ForegroundColour colour)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
}
