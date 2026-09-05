/*
    Program 11: Swap the value of two variables using a third variable
    Topic: Operators
*/
#include <stdio.h>
#include "projects.h"

void program11(void)
{
    int a, b, temp;

    printf("--- Program 11: Swap Using a Third Variable ---\n");
    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);

    printf("Before swapping: a = %d, b = %d\n", a, b);
    temp = a;
    a = b;
    b = temp;
    printf("After swapping : a = %d, b = %d\n", a, b);
}
