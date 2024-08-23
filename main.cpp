#include "TxLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "solvers.h"
#include "input.h"
#include "tester.h"

#define GET_ERROR_STRING(error)               \
    if (error != NO_SOLVER_ERRORS)            \
    {                                         \
        printf("error number %d\n", error);   \
    }

int main(int argc, char *argv[])
{
    struct coefficients abc = {0, 0, 0};
    struct squares x1x2 = {0, 0};
    struct SolveTester ST[8] = {{1, 2, 1, -1, -1, ONE_ROOT},
                                {2, 1, -3, 1, -1.5, TWO_ROOTS},
                                {0, 1, 1, -1, 0, ONE_ROOT},
                                {0, 0, 0, 0, 0, INF_ROOTS},
                                {1, 0, 1, 0, 0, NO_ROOTS},
                                {0, 0, 1, 0, 0, NO_ROOTS},
                                {1, 2, 3, 0, 0, NO_ROOTS},
                                {1, 1, 0, 0, -1, TWO_ROOTS}};

    NumberRoots num_roots = NO_ROOTS;

    if (argc == 2)
    {
        if (strcmp(argv[1], "--test") == 0)
        {
            for (int i = 0; i < 8; i++)
            {
                Tester(&(ST[i]));
            }
            printf("Tests past!");
        }

        if (strcmp(argv[1], "--normal") == 0)
        {
            printf("Enter the coefficients:\n");

            GET_ERROR_STRING(InputCoeff(&(abc.a)));
            GET_ERROR_STRING(InputCoeff(&(abc.b)));
            GET_ERROR_STRING(InputCoeff(&(abc.c)));

            Solver(&abc, &x1x2, &num_roots);
            GetAnswer(&x1x2, num_roots);
        }
    }
    else
    {
        printf("Error");
    }

    return 0;
}



