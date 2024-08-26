#include <stdio.h>
#include "..\include\solvers.h"
#include "..\include\input.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/**
    \file
    \brief Файл выполнения функции, проверяющей ошибки ввода.
*/
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

        if (counts_not_error == 3)
        {
            return READING_ERROR;
        }

        printf("Your symbol isn't correct. Try again\n");

    }

    return NO_SOLVER_ERRORS;
}
