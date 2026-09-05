/*
    Program 04: Check whether a number is even or odd
    Topic: Conditional Statements
*/
#include <stdio.h>
#include "projects.h"

void program04(void)
{
    int num;
    printf("--- Program 04: Even or Odd ---\n");
    printf("Enter your number: ");
    scanf("%d", &num);

    if (num % 2 == 0)
        printf("Even number\n");
    else
        printf("Odd number\n");
}
