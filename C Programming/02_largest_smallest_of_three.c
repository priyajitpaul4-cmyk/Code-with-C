/*
    Program 02: Find the largest and smallest among three numbers
    Topic: Conditional Statements
*/
#include <stdio.h>
#include "projects.h"

void program02(void)
{
    int a, b, c;
    printf("--- Program 02: Largest and Smallest of Three Numbers ---\n");
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a < b && a < c)
        printf("%d is the smallest number\n", a);
    else if (b < a && b < c)
        printf("%d is the smallest number\n", b);
    else
        printf("%d is the smallest number\n", c);

    if (a > b && a > c)
        printf("%d is the largest number\n", a);
    else if (b > a && b > c)
        printf("%d is the largest number\n", b);
    else
        printf("%d is the largest number\n", c);
}
