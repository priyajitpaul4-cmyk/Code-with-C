/*
    Program 15: Find the factorial of a number using recursion
    Topic: Recursion
*/
#include <stdio.h>
#include "projects.h"

static long fact(int num)
{
    if (num == 0 || num == 1)
        return 1;
    else
        return num * fact(num - 1);
}

void program15(void)
{
    int num;

    printf("--- Program 15: Factorial (Recursive) ---\n");
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0)
    {
        printf("Factorial not possible for a negative number.\n");
        return;
    }

    printf("Factorial is: %ld\n", fact(num));
}
