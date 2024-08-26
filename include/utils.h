#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/**
    \file
    \brief Заголовочный файл с прототипом функций и константой.

    Данные функции используются при сравнении чисел double, а константа, которая инициализируется
    в файле используется при сравнении.
*/

/// переменная в экспоненциальной форме, использующаяся при сравнении чисел, имеющих тип данных double.
const double EPS = 1e-9;

/**
    \brief функция, проверяющая числа double на равенство.

    \param [in] a - double число
    \param [in] b - double число
*/
bool CompareEqual(double a, double b);

/**
    \brief функция, проверяющая, что одно число double больше или меньше другого.

    \param [in] a - double число
    \param [in] b - double число
*/
bool CompareMore(double a, double b);

#endif // UTILS_H_INCLUDED
