/*
    Program 20: Add numbers using an array
    Topic: Arrays & Hashing
*/
#include <stdio.h>
#include "projects.h"

void program20(void)
{
    int i, n, sum = 0;
    int arr[100];

    printf("--- Program 20: Sum of Numbers Using an Array ---\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Please enter a size between 1 and 100.\n");
        return;
    }

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < n; i++)
        sum = sum + arr[i];

    printf("Sum is: %d\n", sum);
}
