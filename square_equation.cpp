#include "TxLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void LinealEquation(float b, float c);

void QuadroEquation(float a, float b, float c);

int main()
{

    float a=0.5;

    float b=0.5;

    float c=0.5;

    printf("Enter the coefficients of quadratic equation:\n");

    while(scanf("%f %f %f",&a,&b,&c)==3)
    {
        if (a==0)
        {
            LinealEquation(b,c);

            continue;
        }
        else
        {
            QuadroEquation(a,b,c);

            continue;
        }
    }
    printf("Program ended.");

    return 0;
}

void LinealEquation(float b, float c)
{
    if((b!=0)&&(c!=0))
    {
        printf("Equation isn't quadro. Root only one %f\n", -c/b);

        printf("Enter the other coefficients of quadratic equation:\n");
    }
    else if((b==0)&&(c==0))
    {
        printf("There isn't a border in solving this equation\n");

        printf("Enter the other coefficients of quadratic equation:\n");
    }
    else if((b==0)&&(c!=0))
    {
        printf("There aren't any solvers in this equation\n");

        printf("Enter the other coefficients of quadratic equation:\n");
    }
    else
    {
        printf("Equation isn't quadro. Root only one equal 0\n");

        printf("Enter the other coefficients of quadratic equation:\n");
    }
}

void QuadroEquation(float a, float b, float c)
{
    float D = b*b-4*a*c;

    if(D<0)
    {
        printf("oh,no!\n");

        printf("It equation doesn't have roots.\n");

    }
    else if (D==0)

       printf("only one square:%f\n",-b/(2*a));

    else

        printf("two squares: %f %f\n",(-b+sqrt(D))/(2*a),(-b-sqrt(D))/(2*a));

    printf("Enter the other coefficients of quadratic equation:\n");
}











