/*
    Program 22: Find duplicate elements in an array using hashing
    Topic: Arrays & Hashing
    (New - from the "Arrays & Hashing" roadmap node. Uses a simple
    "seen" lookup table (a hash-by-value array) so each element is
    checked in O(1) instead of comparing every pair - the core idea
    behind hashing.)
*/
#include <stdio.h>
#include "projects.h"

#define TABLE_SIZE 1000

void program22(void)
{
    int arr[100];
    int seen[TABLE_SIZE] = {0};   /* seen[v] = 1 means value v has appeared */
    int n, i, found_duplicate = 0;

    printf("--- Program 22: Find Duplicates Using Hashing ---\n");
    printf("Enter number of elements (values must be 0 to %d): ", TABLE_SIZE - 1);
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Please enter a size between 1 and 100.\n");
        return;
    }

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Duplicate elements: ");
    for (i = 0; i < n; i++)
    {
        if (arr[i] < 0 || arr[i] >= TABLE_SIZE)
        {
            printf("\nValue %d is out of the supported 0-%d range, skipping.\n",
                   arr[i], TABLE_SIZE - 1);
            continue;
        }

        if (seen[arr[i]] == 1)
        {
            printf("%d ", arr[i]);
            found_duplicate = 1;
        }
        else
        {
            seen[arr[i]] = 1;
        }
    }

    if (!found_duplicate)
        printf("None found");
    printf("\n");
}
