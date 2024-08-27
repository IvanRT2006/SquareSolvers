#ifndef SOLVERS_H_INCLUDED
#define SOLVERS_H_INCLUDED

/**
    \file
    \brief Заголовочный файл с описанием перечислительных типов данных, структур и
    прототипов функций.

    Данный файл содержит в себе описание основных структур и основных прототипов функций,
    которые используются в демонстрационной программе.

*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <windows.h>

/**
    \brief перечислительный тип данных, передающий цвета.
*/

enum ForegroundColour
{
    /// красный цвет
    RED = FOREGROUND_RED,
    /// синий цвет
    BLUE = FOREGROUND_BLUE,
    /// зеленый цвет
    GREEN = FOREGROUND_GREEN,
    /// желтый цвет
    YELLOW = FOREGROUND_RED,
    /// сочетание цветов, с помощью которых можно получить любой цвет
    BASE = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN,
};


/**
    \brief перечислительный тип данных, передающий ошибки,
    возникающие при вводе пользователем коэффициентов квадратного уравнения,
    а также при его решении.
 */

enum SolverErrors
{
    /// @brief переменная, которая возвращается, если допущены ошибки
    UNDEFINED_NUMBER_ROOTS = -1000,
    /// @brief переменная, которая возвращается, если нет ошибок.
    NO_SOLVER_ERRORS = 0,
    /// @brief переменная. обозначающая ошибки при чтении
    READING_ERROR = 100,
};

/**
    \brief перечислительный тип данных, обозначающий
    количество корней квадратного уравнения.
 */

enum NumberRoots
{
   /// перменная, обозначающая, что уравнение имеет бесконечно много решений.
   INF_ROOTS = -1,
   /// переменная, обозначающая, что уравнение не имеет решений.
   NO_ROOTS,
   /// переменная, обозначающая, что уравнение имеет 1 решение.
   ONE_ROOT,
   /// переменная, обозначающая, что уравнение имеет 2 решения.
   TWO_ROOTS,
};

/**
    \brief структура коэффициентов квадратного уравнения.
*/

struct coefficients
{
    /// коэффицент квадратного уравнения.
    double a;
    /// коэффицент квадратного уравнения.
    double b;
    /// коэффицент квадратного уравнения.
    double c;
};

/**
    \brief структура корней квадратного уравнения.
*/
struct squares
{
    /// первый корень квадратного уравнения.
    double x1;
    /// второй корень квадратного уравнения.
    double x2;
};

/**
    \brief функция, возвращающая количество корней в случае, когда коэффициент a равен 0,
    ее значение присваивается переменной num_roots.

    \param [in] coefficients *abc - указатель на структуру коэффициентов квадратного уравнения.
    \param [in] coefficients *x1x2 - указатель на структуру корней квадратного уравнения.
*/
NumberRoots SolverLinearEquation(struct coefficients *abc, struct squares *x1x2);

/**
    \brief функция, возвращающая количество корней в случае, когда коэффицент а не равен 0,
    ее значения присваивается переменной num_roots.

    \param [in] coefficients *abc - указатель на структуру коэффициентов квадратного уравнения.
    \param [in] coefficients *x1x2 - указатель на структуру корней квадратного уравнения.
*/
NumberRoots SolverQuadroEquation(struct coefficients *abc, struct squares *x1x2);

/**
    \brief функция, которая выводит сообщение о количестве корней в зависимости
    от параметра num_roots и возвращает сами корни, если они есть.

    \param [in] coefficients *abc - указатель на структуру коэффициентов квадратного уравнения.
    \param [in] coefficients *x1x2 - указатель на структуру корней квадратного уравнения.
 */
SolverErrors GetAnswer(struct squares *x1x2, NumberRoots num_roots);

/**
    \brief функция, которая получает количество корней уравнения и передает их
    в функцию SolverErrors GetAnswer.

    \param [in] coefficients *abc - указатель на структуру коэффициентов квадратного уравнения.
    \param [in] coefficients *x1x2 - указатель на структуру корней квадратного уравнения.
    \param [in] num_roots - адрес на количество решений квадратного уравнения.
*/
NumberRoots Solver(struct coefficients *abc, struct squares *x1x2, NumberRoots *num_roots);

/**
    \brief функция, которая перекрашивает определенную надпись в нужный цвет.

    \param [in] colour - набор цветов, которыми подсвечиваются надписи при выводе информации
    о количестве корней и самих корнях.
*/
void Color(ForegroundColour colour);

#endif // SOLVERS_H_INCLUDED
