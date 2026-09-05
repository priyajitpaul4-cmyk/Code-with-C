/*
    Program 18: Armstrong check - either a single number, or all
                Armstrong numbers in a range
    Topic: Loops + Functions
*/
#include <stdio.h>
#include "projects.h"

static int is_armstrong(int num)
{
    int sum = 0;
    int original_num = num;

    while (num != 0)
    {
        int digit = num % 10;
        num = num / 10;
        sum = sum + digit * digit * digit;
    }
    return (sum == original_num);
}

void program18(void)
{
    int option;

    printf("--- Program 18: Armstrong Check ---\n");
    printf("1. Check a single number\n");
    printf("2. List Armstrong numbers in a range\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    if (option == 1)
    {
        int num;
        printf("Enter the number: ");
        scanf("%d", &num);
        if (is_armstrong(num))
            printf("%d is an Armstrong number\n", num);
        else
            printf("%d is not an Armstrong number\n", num);
    }
    else if (option == 2)
    {
        int lower, upper, i, found = 0;
        printf("Enter lower bound: ");
        scanf("%d", &lower);
        printf("Enter upper bound: ");
        scanf("%d", &upper);

        printf("Armstrong numbers between %d and %d: ", lower, upper);
        for (i = lower; i <= upper; i++)
        {
            if (is_armstrong(i))
            {
                printf("%d ", i);
                found = 1;
            }
        }
        if (!found)
            printf("None found");
        printf("\n");
    }
    else
    {
        printf("Invalid choice.\n");
    }
}
