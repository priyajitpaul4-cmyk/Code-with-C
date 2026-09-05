/*
    Program 21: Print the smallest element of an array
    Topic: Arrays & Hashing
*/
#include <stdio.h>
#include "projects.h"

void program21(void)
{
    int n, i;
    int arr[100];
    int min;

    printf("--- Program 21: Smallest Element of an Array ---\n");
    printf("Enter how many elements you want to insert: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Please enter a size between 1 and 100.\n");
        return;
    }

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    min = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }

    printf("Smallest element in this array is: %d\n", min);
}
