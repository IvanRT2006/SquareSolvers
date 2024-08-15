#include "TxLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

const double eps = 1e-9;

int SolverLinearEquation(double b, double c, double *x1);
int SolverQuadroEquation(double a, double b, double c, double *x1, double *x2);
bool CompareEqual(double a, double b);
bool CompareMore(double a, double b);
void GetAnswer(double x1, double x2, int num_roots);

int main()
{
    double a, b, c, x1, x2 = 0;
    int num_roots = 0;

    printf("Enter the coefficients:\n");

    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    if (a == 0)
    {
        num_roots = SolverLinearEquation(b, c, &x1);
    }

    else
    {
        num_roots = SolverQuadroEquation(a, b, c, &x1, &x2);
    }

  GetAnswer(x1, x2, num_roots);

  printf("Program ended");

  return 0;
}

void GetAnswer(double x1, double x2, int num_roots)
{
    switch(num_roots)
    {
        case -1:
            printf("Solvers in this equation don't have borders\n");
            break;
        case 0:
            printf("Not solvers in this equation!\n");
            break;
        case 2:
            printf("Two roots: x1 = %lf, x2 = %lf\n", x1, x2);
            break;
        case 1:
            printf("Only one root: x1 = %lf\n", x1);
            break;
        case 11:
            printf("Only one root: x1 = %lf x2 = %lf\n", x1, x2);
            break;
    }
}

int SolverLinearEquation(double b, double c, double *x1)
{
    int num_roots = 0;

    if (CompareEqual(b, 0) == true)
    {
        if (CompareEqual(c, 0) == true)
        {
            num_roots = -1;
        }
        else
        {
            num_roots = 0;
        }
    }
    else
    {
        num_roots = 1;
        *x1 = -c/b;
    }

    return num_roots;
}

int SolverQuadroEquation(double a, double b, double c, double *x1, double *x2)
{
    int num_roots = 0;
    const double D = b * b - 4 * a * c;

    if (CompareEqual(D, 0) == true)
    {
         num_roots = 11;
         *x1 = -b / (2 * a);
         *x2 = 0;
    }
    else
    {
        if (CompareMore(D, 0) == true)
        {
            num_roots = 2;
            *x1 = (-b + sqrt(D)) / (2 * a);
            *x2 = (-b - sqrt(D)) / (2 * a);
        }
        else
        {
            num_roots = 0;
        }
    }

    return num_roots;
}

bool CompareEqual(double a, double b)
{
    if (abs(a - b) < eps)
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
    if ((a - b) > eps)
    {
        return true;
    }

    else
    {
        return false;
    }
}
