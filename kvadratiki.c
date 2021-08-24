#include <stdio.h>
#include <math.h>


int main(void)
{
    float a, b, c; 
    float D, x1, x2, di;
    printf("Введите коэфициенты в квадратном уравнении вида: ax^2 + bx + c = 0 ");
    printf("Для завершения нажмите s\n");

    
    while (scanf("%f %f %f", &a, &b, &c) == 3)
    {
        D = b*b - 4*a*c;
        if (D < 0)
            printf("корней нет\n");
        else if (D == 0)
            printf("уравнение имеет один квадратный корень, который равен %.2f\n", -b/(2*a));
        else
        {
            di = sqrt(D);
            x1 = (-b-di)/(2*a);
            x2 = (-b+di)/(2*a);
            printf("%lf %lf - корни уравнения\n", x1, x2);
            
        }
        printf("Введите следующие числа для анализа ");
        printf("для завершения введите s.\n");
        
    }


    return 0;
}




