/*
    Program 16: Print the Fibonacci series up to n terms
    Topic: Loops
*/
#include <stdio.h>
#include "projects.h"

void program16(void)
{
    int n, i;
    long t1 = 0, t2 = 1, next;

    printf("--- Program 16: Fibonacci Series ---\n");
    printf("Enter number of terms: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Please enter a positive number of terms.\n");
        return;
    }

    printf("Fibonacci series: ");
    for (i = 1; i <= n; i++)
    {
        if (i == 1)
            next = t1;
        else if (i == 2)
            next = t2;
        else
        {
            next = t1 + t2;
            t1 = t2;
            t2 = next;
        }
        printf("%ld ", next);
    }
    printf("\n");
}
