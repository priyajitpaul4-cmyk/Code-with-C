/*
    Program 10: Menu driven program for Addition, Subtraction,
                Multiplication and Division using switch case
    Topic: Switch Case
*/
#include <stdio.h>
#include "projects.h"

void program10(void)
{
    int option;
    int num1, num2;

    printf("--- Program 10: Menu Driven Arithmetic ---\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    printf("Enter your option: ");
    scanf("%d", &option);

    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    switch (option)
    {
        case 1:
            printf("Addition of two numbers is: %d\n", num1 + num2);
            break;
        case 2:
            printf("Subtraction of two numbers is: %d\n", num1 - num2);
            break;
        case 3:
            printf("Multiplication of two numbers is: %d\n", num1 * num2);
            break;
        case 4:
            if (num2 == 0)
                printf("Division by zero is not allowed.\n");
            else
                printf("Division of two numbers is: %.2f\n", (float)num1 / num2);
            break;
        default:
            printf("Enter a valid option.\n");
            break;
    }
}
