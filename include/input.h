#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <stdlib.h>

/**
    \file
    \brief Заголовочный файл с прототипом функции

    Данный файл содержит в себе информацию о функции, обрабатывающих ошибки при вводе.
*/

/**
    \brief функция, обрабатывающая ошибки ввода коэффициентов квадратного уравнения.
    \param [in] coeff - адрес коэффициента квадратного уравнения.
*/
SolverErrors InputCoeff(double *coeff);

#endif // INPUT_H_INCLUDED
