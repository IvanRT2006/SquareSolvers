#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include "..\include\solvers.h"
#include "..\include\input.h"
#include "..\include\tester.h"

/**
    \file
    \brief Файл с выполнением функции по решению квадратного уравнения.
*/

#define GET_ERROR_STRING(error)               \
    if (error != NO_SOLVER_ERRORS)            \
    {                                         \
        printf("error number %d\n", error);   \
    }

int main(int argc, char *argv[])
{
    struct coefficients abc = {0, 0, 0};
    struct squares x1x2 = {0, 0};
    struct SolveTester ST[8] = {{1, 2,  1, -1,   -1, ONE_ROOT},
                                {2, 1, -3,  1, -1.5, TWO_ROOTS},
                                {0, 1,  1, -1,    0, ONE_ROOT},
                                {0, 0,  0,  0,    0, INF_ROOTS},
                                {1, 0,  1,  0,    0, NO_ROOTS},
                                {0, 0,  1,  0,    0, NO_ROOTS},
                                {1, 2,  3,  0,    0, NO_ROOTS},
                                {1, 1,  0,  0,   -1, TWO_ROOTS}};

    NumberRoots num_roots = NO_ROOTS;

    if (argc == 2)
    {
        if (strcmp(argv[1], "--test") == 0)
        {
            for (int i = 0; i < 8; i++)
            {
                Tester(&(ST[i]));
            }

            Color(GREEN);
            printf("Tests past! Enter --normal for start of program");
            Color(BASE);
            getch();
        }

        else if (strcmp(argv[1], "--normal") == 0)
        {
            Color(GREEN);
            printf("Enter the coefficients:");
            Color(BASE);
            getch();

            GET_ERROR_STRING(InputCoeff(&(abc.a)));
            GET_ERROR_STRING(InputCoeff(&(abc.b)));
            GET_ERROR_STRING(InputCoeff(&(abc.c)));

            Solver(&abc, &x1x2, &num_roots);
            GetAnswer(&x1x2, num_roots);
        }
        else
        {
            Color(RED);
            printf("Error. Enter --help for better information\n");
            Color(BASE);
            getch();
        }
    }
    else
    {
        Color(RED);
        printf("Error. Enter --help for better information\n");
        Color(BASE);
        getch();
    }

    return 0;
}
