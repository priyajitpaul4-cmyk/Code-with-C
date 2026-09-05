/*
    Program 13: Swap two numbers using pointers
    Topic: Pointers
*/
#include <stdio.h>
#include "projects.h"

static void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void program13(void)
{
    int a, b;

    printf("--- Program 13: Swap Using Pointers ---\n");
    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);

    printf("Before swapping: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After swapping : a = %d, b = %d\n", a, b);
}
