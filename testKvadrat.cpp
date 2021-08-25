#include "quadric.h"



bool test()
{
    bool flag = true;
    int current_test = 1;
    if (EquationSol(7, 5, 6, &x1, &x2) != 0)
    {
        printf("i failed %d test", current_test);
        flag = false;
    }
    current_test++;

    if (EquationSol(7, 5, 6, &x1, &x2) != 0)
    {
        printf("i failed %d test", current_test);
        flag = false;
    }
    current_test++;

    if (EquationSol(7, 5, 6, &x1, &x2) != 0)
    {
        printf("i failed %d test", current_test);
        flag = false;
    }
    current_test++;

    if (EquationSol(7, 5, 6, &x1, &x2) != 0)
    {
        printf("i failed %d test", current_test);
        flag = false;
    }
    current_test++;

    if (EquationSol(7, 5, 6, &x1, &x2) != 0)
    {
        printf("i failed %d test", current_test);
        flag = false;
    }
    



    return flag;
}