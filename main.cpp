#include "TxLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

const double eps = 1e-9;

void LinealEquation(double b, double c);
void QuadroEquation(double a, double b, double c);
bool CompareEqual(double a, double b);
bool CompareMore(double a, double b);

int main()
{
    double a = 0;
    double b = 0;
    double c = 0;

    printf("Enter the coefficients of quadratic equation:\n");

    while (scanf("%lf %lf %lf",&a, &b, &c)==3)
    {
        if (CompareEqual(a,0) == true)
        {
            LinealEquation(b, c);
            continue;
        }
        else
        {
            QuadroEquation(a, b, c);
            continue;
        }
    }

    printf("Program ended.");

    return 0;
}

void LinealEquation(double b, double c)
{
    if (CompareEqual(b, 0) == true)
    {
        if (CompareEqual(c, 0) == true)
        {
            printf("Solvers in this equation don't have borders\n");
        }

        else
        {
            printf("Not solvers in this equation\n");
        }
    }

    else
    {
        printf("Lineal Equation! Only one root %lf\n", -c/b);
    }

    printf("Enter other coefficients:\n");
}

void QuadroEquation(double a, double b, double c)
{
    const double D = b * b - 4 * a * c;

    if (CompareEqual(D, 0) == true)
    {
        const double only_one_root = -b / (2 * a);

        printf("only one root %lf\n", only_one_root);
    }

    else
    {
        if (CompareMore(D, 0) == true)
        {
            const double first_root = (-b + sqrt(D)) / (2 * a);
            const double second_root = (-b - sqrt(D)) / (2 * a);

            printf("Two roots: %lf %lf\n", first_root, second_root);
        }

        else
        {
            printf("Oh no!Not roots\n");
        }
    }

    printf("Enter other coefficients:\n");
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

