#ifndef TESTER_H_INCLUDED
#define TESTER_H_INCLUDED

#include <stdio.h>
#include "solvers.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/**
    \file
    \brief Данный файл содержит информацию о структуре и прототипе функции.

    Данная структура содержит коэффициенты квадратного уравнения и  его ожидаемые корни,
    а функция обрабатывает тесты, использующиеся в программе.
*/

/**
    \brief Структура квадратного уравнения
*/

struct SolveTester
{
    /// коэффициент квадратного уравнения
    double a;
    /// коэффициент квадратного уравнения
    double b;
    /// коэффициент квадратного уравнения
    double c;
    /// ожидаемый корень квадратного уравнения
    double x1expected;
    /// ожидаемый корень квадратного уравнения
    double x2expected;
    /// количество корней квадратного уравнения
    NumberRoots num_roots;
};

/**
    \brief функция, обрабатывающая тесты.

    \param SolverTester *ST - указатель на структуру, которая используется при проверке
    тестов над квадратным уравнением.
*/
int Tester(struct SolveTester *ST);

#endif // TESTER_H_INCLUDED
