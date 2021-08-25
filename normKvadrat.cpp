#include "quadric.h"

int SolveQuadraticEquation(double a, double b, double c, double* x1, double* x2);
int SolveLinearEquation(double b, double c, double* x1);
int EquationSol(double a, double b, double c, double* x1,double* x2);
bool IsZero(double n);



const int infinity = -1;
const double precision = 1e-6;
int main()
{
    
    printf("Enter the coefficients of the equation a, b, c: ");
    
    double a = 0, b = 0, c = 0;
    scanf("%lf %lf %lf", &a, &b, &c);

    double x1 = 0, x2 = 0;
    int numofroots = EquationSol(a, b, c, &x1, &x2);

    switch (numofroots)
    {
        case 0: printf("No roots\n");
                break;
        
        case 1: printf("x = %lf", x1);
                break;
        
        case 2: printf("x1 = %lf x2 = %lf", x1, x2);
                break;

        case infinity: printf("infinite number of roots");
                break;
        
        default: printf("ERROr : number of roots is %d", numofroots);

    }

    return 0;
}


int EquationSol(double a, double b, double c, double* x1,double* x2)
{
    if (IsZero(a))
    {
        return SolveLinearEquation(b, c, x1);
    }

    else
    {   
        return SolveQuadraticEquation(a, b, c, x1, x2);
    }
}




int SolveLinearEquation(double b, double c, double* x1)
{
    if (IsZero(b))
    {
        return (IsZero(c)) ? -1 : 0;
    }
    else 
    {
        *x1 = -c / b;
        return 1;
    }

}

int SolveQuadraticEquation(double a, double b, double c, double* x1, double* x2)
{
    double d = b * b - 4 * a * c;

    if (d < 0)
    {
        return 0;
    }
    else if (IsZero(d)) 
    {
        *x1 = *x2 = -b /(2 * a);
        return 1;
    }
    else
    {
        double d_sqrt = sqrt(d);
        *x1 = (-b + d_sqrt)/(2 * a);
        *x2 = (-b - d_sqrt)/(2 * a);
        return 2;

    }

}


bool IsZero(double n)
{
    return fabs(n) < precision;
}
