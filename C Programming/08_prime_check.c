/*
    Program 08: Prime check - either a single number, or all primes in a range
    Topic: Loops + Functions
*/
#include <stdio.h>
#include "projects.h"

static int check_prime(int num)
{
    int i;
    if (num <= 1)
        return 0;
    for (i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

void program08(void)
{
    int option;

    printf("--- Program 08: Prime Check ---\n");
    printf("1. Check a single number\n");
    printf("2. List primes in a range\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    if (option == 1)
    {
        int num;
        printf("Enter number: ");
        scanf("%d", &num);
        if (check_prime(num))
            printf("%d is a prime number\n", num);
        else
            printf("%d is not a prime number\n", num);
    }
    else if (option == 2)
    {
        int lower, higher, i;
        printf("Enter lower number: ");
        scanf("%d", &lower);
        printf("Enter higher number: ");
        scanf("%d", &higher);

        if (lower > higher)
        {
            printf("Lower number must not be greater than higher number.\n");
            return;
        }

        printf("Prime numbers between %d and %d:\n", lower, higher);
        for (i = lower; i <= higher; i++)
        {
            if (check_prime(i))
                printf("%d\n", i);
        }
    }
    else
    {
        printf("Invalid choice.\n");
    }
}
