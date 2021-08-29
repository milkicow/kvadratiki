
#include "Quadric.h"



#include "testQuadric.cpp"

int main()
{
    int first_input = 0;
    int c = 0;

    printf("if you want to decide the equation press 1 (press q to leave)\n");
    printf("if you want to test the program press 0\n");
    
    while (scanf("%d", &first_input) == 1)
    {
        if (first_input)
        {
            printf("Enter the coefficients of the equation a, b, c: ");
        
            double a = NAN, b = NAN, c = NAN;
            if (scanf("%lf %lf %lf", &a, &b, &c) == 3)
            {
                PrintAnswer(a, b, c);
            }
            else 
            {
                printf("incorrect input\n");
                ClearBuf(); 
            }
                
            printf("if you want to decide the equation press 1 (press q to leave)\n");
            printf("if you want to test the program press 0\n");
            
        }
        else
        {
            if (Test() == false) 
                return -1;
            else 
            {
                printf("if you want to decide the equation press 1 (press q to leave)\n");
                printf("if you want to test the program press 0\n");
            }
        }

    }

    return 0;
}



int EquationSol(double a, double b, double c, double* x1, double* x2)
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




int SolveLinearEquation(double b, double c, double* x)
{      
    assert (isfinite (b));
    assert (isfinite (c));

    assert (x != NULL);

    if (IsZero(b))
    {
        return (IsZero(c)) ? Infinity : 0;
    }
    else 
    {
        *x = -c / b;
        return 1;
    }

}

int SolveQuadraticEquation(double a, double b, double c, double* x1, double* x2)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);
    
    
    double discr = b * b - 4 * a * c;

    if (IsZero(discr)) 
    {
        *x1 = *x2 = -b /(2 * a);
        return 1;
    }
    else if (discr < 0) //d = -0.0000000005
    {
        return 0;
    }
    else
    {
        double d_sqrt = sqrt(discr);
        *x1 = (-b + d_sqrt)/(2 * a);
        *x2 = (-b - d_sqrt)/(2 * a);
        return 2;

    }

}

//static inline 
bool IsEqual(double a, double b)
{   
    assert (isfinite (a));
    assert (isfinite (b));
   
    return (IsZero(a - b));
}

//static inline 
bool IsZero(double n)
{   
    return (fabs(n) < Precision);
}

void ClearBuf()
{
    while(getchar() != '\n')  {;} 

}


void PrintAnswer(double a, double b, double c)
{
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

        case Infinity: printf("infinite number of roots\n");
                       break;
                    
        default: printf("ERROr : number of roots is %d\n", num_of_roots);
    }
}