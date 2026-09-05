/*
    Program 26: Binary search for a target value in a sorted array
    Topic: Binary Search
    (New - from the roadmap's "Binary Search" node. Repeatedly checks
    the middle element and discards the half the target cannot be in,
    giving O(log n) instead of the O(n) of a linear scan.)
*/
#include <stdio.h>
#include "projects.h"

void program26(void)
{
    int arr[100];
    int n, i, target, low, high, mid;
    int position = -1;

    printf("--- Program 26: Binary Search ---\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Please enter a size between 1 and 100.\n");
        return;
    }

    printf("Enter %d elements in ascending (sorted) order: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter target value: ");
    scanf("%d", &target);

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            position = mid;
            break;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (position != -1)
        printf("%d found at index %d\n", target, position);
    else
        printf("%d not found in the array\n", target);
}
