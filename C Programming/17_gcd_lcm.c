/*
    Program 17: Find the GCD and LCM of two numbers
    Topic: Functions
*/
#include <stdio.h>
#include "projects.h"

static int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void program17(void)
{
    int a, b, g, l;

    printf("--- Program 17: GCD and LCM ---\n");
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    if (a == 0 || b == 0)
    {
        printf("Both numbers must be non-zero.\n");
        return;
    }

    g = gcd(a, b);
    l = (a / g) * b;

    printf("GCD is: %d\n", g);
    printf("LCM is: %d\n", l);
}
