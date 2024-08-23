#include "TxLib.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "solvers.h"
#include "utils.h"

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
