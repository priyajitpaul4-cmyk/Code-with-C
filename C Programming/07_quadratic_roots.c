/*
    Program 07: Check whether real roots of a quadratic equation exist; if they exist, find them
    Topic: Conditional Statements + Math library
*/
#include <stdio.h>
#include <math.h>
#include "projects.h"

void program07(void)
{
    float a, b, c, discriminant, root1, root2;

    printf("--- Program 07: Roots of a Quadratic Equation ---\n");
    printf("Enter coefficients a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);

    if (a == 0)
    {
        printf("Coefficient 'a' cannot be 0 (not a quadratic equation)\n");
        return;
    }

    discriminant = b * b - 4 * a * c;

    if (discriminant >= 0)
    {
        printf("Real roots exist.\n");
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Root 1 is: %.2f\nRoot 2 is: %.2f\n", root1, root2);
    }
    else
    {
        printf("No real roots exist (roots are complex/imaginary).\n");
    }
}
