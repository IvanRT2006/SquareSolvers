#include <stdio.h>
#include "..\include\utils.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/**
    \file
    \brief Файл с выполнением функций сравнения чисел double.
*/

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
