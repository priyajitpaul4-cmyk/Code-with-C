/*
    Program 19: Find the sum of the digits of a number
    Topic: Loops
*/
#include <stdio.h>
#include "projects.h"

void program19(void)
{
    int num, last_digit, sum = 0;

    printf("--- Program 19: Sum of Digits ---\n");
    printf("Enter a number: ");
    scanf("%d", &num);

    while (num != 0)
    {
        last_digit = num % 10;
        num = num / 10;
        sum = sum + last_digit;
    }

    printf("Sum of all digits is: %d\n", sum);
}
