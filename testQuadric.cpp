#include "Quadric.h"


bool Test() 
{   
    double a = 0, b = 0, c = 0; 
    double x1 = 0, x2 = 0;
    double r1 = 0, r2 = 0;

    bool flag = true;
    bool correct_input = true;

    int current_test = 1;
    int fail_tests = 0;

    int num_of_roots = NAN;
    int nroots = NAN;


    FILE* fp = NULL;
    fp = fopen("test.txt", "r");
    
    assert(fp != NULL); 
    
    while (feof(fp) == 0) // struct Test {a, b, c, num_of_roots, x1, x2, ans1, ans2, num_of_roots_ans}
    {   
        if (fscanf(fp, "%lf %lf %lf %d %lf %lf", &a, &b, &c, &num_of_roots, &r1, &r2) == 6)
        {
            // check_answer(struct Test* test);
            CheckAnswer(nroots, num_of_roots, a, b, c, x1, x2, &flag, &current_test, &fail_tests, r1, r2);
        }
        else
        {   
            if (feof(fp) == 0)
            {
                printf("incorrect input in %d test\n", current_test);
                correct_input = false;
                break;          
            }
        }
    }

    if (fail_tests == 0 && correct_input)
    {
        printf("successfully!!!\n");
    }
    else
    {
        printf("program failed %d test(s)\n", fail_tests);
    }
    
    fclose(fp);

    return flag;
}


void FailedTest(bool* flag, int* current_test, int* fail_tests, int nroots, int num_of_roots)
{   
    printf("i failed %d test\n", *current_test);
    *flag = false;
    *fail_tests += 1;
    printf("nroots = %d, should be: %d \n", nroots, num_of_roots);
}



void CheckAnswer(int nroots, int num_of_roots, double a, double b, double c, double x1, double x2, bool* flag, int* current_test, int* fail_tests, double r1, double r2)
{
    nroots = EquationSol(a, b, c, &x1, &x2);

    // check_answer(struct Test* test);
    switch(num_of_roots)
    {
        case 0:
        {
            if (nroots != 0)
            {
                FailedTest(flag, current_test, fail_tests, nroots, num_of_roots);
            }
            break;
        }
        case 1:
        {
            if (nroots != 1 || !IsEqual(r1, x1) )
            {
                FailedTest(flag, current_test, fail_tests, nroots, num_of_roots);
                printf("x1 = %lf, should be: %lf \n", x1, r1);
            }
            break;
        }
        case 2:
        {
            if (nroots != 2 || (!IsEqual(r1, x1) || !IsEqual(r2, x2)) && (!IsEqual(r2, x1) || !IsEqual(r1, x2)))
            {
                FailedTest(flag, current_test, fail_tests, nroots, num_of_roots);
                printf("x1 = %lf, x2 = %lf, should be: %lf, %lf \n", x1, x2, r1, r2);
            }
            break;
        }
        case Infinity:
        {
            if (nroots != -1)
            {
                FailedTest(flag, current_test, fail_tests, nroots, num_of_roots);
            }
            break;
        }
        default: 
        {
            printf("ERROr : number of roots is %d\n", num_of_roots);
            FailedTest(flag, current_test, fail_tests, nroots, num_of_roots);

        }

    }
    *current_test += 1;
}