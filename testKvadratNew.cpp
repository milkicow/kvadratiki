#include "quadric.h"

bool test() 

{   

    double a, b, c; 
    double x1 = 0, x2 = 0;
    double r1, r2;

    bool flag = true;
    int current_test = 1;
    int failtests = 0;

    int num_of_roots;

    FILE* fp;
    fp = fopen("test.txt", "r");

    
    while (feof(fp) == 0)
    {   
        fscanf(fp, "%lf %lf %lf %d %lf %lf", &a, &b, &c, &num_of_roots, &r1, &r2);
        // nroots = EquationSol убрать вызов из ифов
        if (num_of_roots == 0)
        {
            if (zEquationSol(a, b, c, &x1, &x2) != 0)
            {
                printf("i failed %d test\n", current_test);
                flag = false;
                failtests++;
            }
        }

        else if (num_of_roots == 1)
        {
            if ((EquationSol(a, b, c, &x1, &x2) != 1) || r1 != x1 )
            {
                printf("i failed %d test\n", current_test);
                flag = false;
                failtests++;
            }


        }

        else if (num_of_roots == 2)
        {
            if ((EquationSol(a, b, c, &x1, &x2) != 2) || r1 != x1 || r2 != x2)
            {
                printf("i failed %d test\n", current_test);
                flag = false;
                failtests++;
            }
        }

        else if (num_of_roots == -1)
        {
            if (EquationSol(a, b, c, &x1, &x2) != -1)
            {
                printf("i failed %d test\n", current_test);
                flag = false;
                failtests++;
            }
        }

        current_test++;
    }

    if (failtests == 0)
    {
        printf("successfully!!!\n");
        
    }
    else
    {
        printf("program failed %d tests\n", failtests);
    }
    
    fclose(fp);

    return flag;
}