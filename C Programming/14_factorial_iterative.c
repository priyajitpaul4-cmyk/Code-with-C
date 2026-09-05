/*
    Program 14: Find the factorial of a number (iterative)
    Topic: Loops
*/
#include <stdio.h>
#include "projects.h"

void program14(void)
{
    int num, original_num;
    long fact = 1;

    printf("--- Program 14: Factorial (Iterative) ---\n");
    printf("Enter the number: ");
    scanf("%d", &num);
    original_num = num;

    if (num < 0)
    {
        printf("Factorial not possible for a negative number.\n");
        return;
    }

    while (num > 1)
    {
        fact = fact * num;
        num = num - 1;
    }

    printf("Factorial of %d is: %ld\n", original_num, fact);
}
