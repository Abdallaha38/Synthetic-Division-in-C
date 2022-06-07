#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Declaring variables
    int order1[10], n1;
    float coeff1[10], n2;

    //Intro + Assumptions
    printf("Hello,\nThis program is to divide two polynomials (first divided by second).\n\
The first polynomial orders must be consecutive and ordered from highest to lowest, example:(x^n+x^n-1+x^n-2.....).\n\
    Hint: if you have a polynomial like (x^3+2x+1),\n\
    you can still divide it but make sure to make in the form of (x^3+0x^2+2x+1) to keep the consecutiveness of orders.\n\
The second polynomial must be in the form of(ax + b) where (a = 1) and b is a constant.\n\n");

    //Taking the data form the user
    printf("How many terms do you have in the first polynomial? (after adding extra terms as in the hint if any)\n");
    scanf("%d", &n1);
    printf("\nHint:Term no.1 is the highest order and term no.%d is the lowest.\n\n", n1);
    for(int i = 0; i < n1; i++)
        {
            printf("Enter the coefficient of the term no.%d:\t ", i+1);
            scanf("%f", &coeff1[i]);
            printf("Enter the order of the term no.%d:\t ", i+1);
            scanf("%d", &order1[i]);
        }

    printf("\nEnter the constant of the second polynomial:\t ");
    scanf("%f", &n2);
    printf("\n");

    //Printing the given polynomials for reference
    for(int i = 0; i < n1; i++)
        {
            if(i == n1-1) //To print the last term in the first polynomial
            {
                if(order1[i] != 0) //To remove the xTerm if its power is zero
                {
                    printf("%.0fx^%d  /  ", coeff1[i], order1[i]);
                    break;
                }
                else
                {
                    printf("%.0f  /  ", coeff1[i]);
                    break;
                }

            }
            if(coeff1[i+1]>=0) //To print "+" if +ve and "" if -ve(because -ve nums are printed with their - sign)
                printf("%.0fx^%d +", coeff1[i], order1[i]);
            else
                printf("%.0fx^%d ", coeff1[i], order1[i]);
        }
    if(n2 > 0) //To print "+" if +ve and "" if -ve(because -ve nums are printed with their - sign)
        printf("x +%.0f = ",n2);
    else
        printf("x %.0f = ",n2);

    //Calculating the Division (using synthetic division)
    float coeff_result[10];
    coeff_result[0] = coeff1[0];
    for(int i = 0; i < n1; i++)
    {
        coeff_result[i+1] = coeff1[i+1] - (coeff_result[i]*n2);
    }

    //Printing the result
    for(int i = 0; i < n1; i++)
        {
            if(i == n1-1) //Printing the remainder
            {
                if(coeff_result[i] == 0) //To skip printing the remainder if there's not
                    break;
                else
                if(n2 > 0) //To print "+" if +ve and "" if -ve(because -ve nums are printed with their - sign)
                {
                    printf("%.0f/(x +%.0f)", coeff_result[i], n2);
                    break;
                }
                else
                {
                    printf("%.0f/(x %.0f)", coeff_result[i], n2);
                    break;
                }

            }
            if((order1[i]-1) != 0) //To remove the xTerm if its power is zero
            {
                if(coeff_result[i+1]>=0) //To print "+" if +ve and "" if -ve(because -ve nums are printed with their - sign)
                    printf("%.0fx^%d +", coeff_result[i], order1[i]-1);
                else
                    printf("%.0fx^%d ", coeff_result[i], order1[i]-1);
            }
            else
            {
                if(coeff_result[i+1]>=0) //To print "+" if +ve and "" if -ve(because -ve nums are printed with their - sign)
                    printf("%.0f +", coeff_result[i]);
                else
                    printf("%.0f ", coeff_result[i]);
            }
        }
}
