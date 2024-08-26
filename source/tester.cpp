#include <stdio.h>
#include "..\include\solvers.h"
#include "..\include\tester.h"
#include "..\include\utils.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/**
    \file
    \brief Файл с выполнением функции по проверке тестов.
*/

int Tester(struct SolveTester *ST)
{
    struct coefficients abc = {0,0,0};

    abc.a = ST->a;
    abc.b = ST->b;
    abc.c = ST->c;

    struct squares x1x2 = {0,0};

    x1x2.x1 = ST->x1expected;
    x1x2.x2 = ST->x2expected;

    NumberRoots num_roots_not_expected = NO_ROOTS;

    Solver(&abc, &x1x2, &num_roots_not_expected);

    if ((num_roots_not_expected != (ST->num_roots)) || (!(CompareEqual(x1x2.x1, ST->x1expected))) || (!(CompareEqual(x1x2.x2, ST->x2expected))))
    {
        printf("Error Test: a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, num_roots_not_expected = %d\n"
        "Expected: x1 = %lg, x2 = %lg, num_roots_expected = %d\n",
        ST->a, ST->b, ST->c, x1x2.x1, x1x2.x2, num_roots_not_expected, ST->x1expected, ST->x2expected, ST->num_roots);
    }
    return 0;
}
