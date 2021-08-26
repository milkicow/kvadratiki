#include "quadric.h"
#include "testKvadratNew.cpp"


// Выделить имена констант
const int alotofsol = -1;
const double precision = 1e-6;


int main()
{   
    int vvod = 0;

    printf("if you want to decide the equation press 1 (any number)\n");
    printf("if you want to test the program press 0\n");
    
    while (scanf("%d", &vvod) == 1)
    {
        if (vvod)
        {
            printf("Enter the coefficients of the equation a, b, c: ");
        
            double a = NAN, b = NAN, c = NAN;
            scanf("%lf %lf %lf", &a, &b, &c);

            double x1 = NAN, x2 = NAN;
            int num_of_roots = EquationSol(a, b, c, &x1, &x2);

            switch (num_of_roots)
            {
                case 0: printf("No roots\n");
                        break;
                
                case 1: printf("x = %lf\n", x1);
                        break;
                
                case 2: printf("x1 = %lf x2 = %lf\n", x1, x2);
                        break;

                case -1: printf("infinite number of roots");
                        break;
                
                default: printf("ERROr : number of roots is %d\n", num_of_roots);

            }

        }

        else
        {
            if (test() == false)
                break;
        }

        printf("if you want to decide the equation press 1 (any number)\n");
        printf("if you want to test the program press 0\n");

        

    }


    return 0;
}



int EquationSol(double a, double b, double c, double* x1,double* x2)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

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
    // сделать имя длиннее
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

// IsEqual(a, b)
bool IsZero(double n)
{
    if (fabs(n) < precision)
    {
        return true;
    }
    else 
    {
        return false;
    }

}
