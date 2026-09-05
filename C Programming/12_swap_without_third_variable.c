/*
    Program 12: Swap two variables without using a third variable
    Topic: Operators
*/
#include <stdio.h>
#include "projects.h"

void program12(void)
{
    int a, b;

    printf("--- Program 12: Swap Without a Third Variable ---\n");
    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);

    printf("Before swapping: a = %d, b = %d\n", a, b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("After swapping : a = %d, b = %d\n", a, b);
}
